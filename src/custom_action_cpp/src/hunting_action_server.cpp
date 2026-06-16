#include <functional>
#include <memory>
#include <thread>
#include <map>

#include "custom_action_interfaces/action/hunting.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_action/rclcpp_action.hpp"
#include "rclcpp_components/register_node_macro.hpp"

#include "custom_interfaces/srv/angle.hpp"
#include "turtlesim/msg/pose.hpp"
#include "turtlesim/srv/teleport_relative.hpp"
#include "geometry_msgs/msg/twist.hpp"
#include <pluginlib/class_loader.hpp>
#include <polygon_base/regular_polygon.hpp>
#include "custom_action_cpp/visibility_control.h"

namespace custom_action_cpp
{
class HuntingActionServer : public rclcpp::Node
{
public:
  using Hunting = custom_action_interfaces::action::Hunting;
  using GoalHandleHunting = rclcpp_action::ServerGoalHandle<Hunting>;

  CUSTOM_ACTION_CPP_PUBLIC
  explicit HuntingActionServer(const rclcpp::NodeOptions & options = rclcpp::NodeOptions())
  : Node("hunting_action_server", options)
  {
    using namespace std::placeholders;
    angle_ = this->create_client<custom_interfaces::srv::Angle>("angle");
     try {
      poly_loader_ = std::make_unique<pluginlib::ClassLoader<polygon_base::RegularPolygon>>(
        "polygon_base", "polygon_base::RegularPolygon");
      plugin_length_ = poly_loader_->createSharedInstance("polygon_plugins::Length");
      RCLCPP_INFO(this->get_logger(), "Плагін успішно завантажено.");
      }
    catch (pluginlib::PluginlibException& ex) {
      RCLCPP_ERROR(this->get_logger(), "Не вдалося завантажити плагін: %s", ex.what());
    } 

    auto handle_goal = [this](
      const rclcpp_action::GoalUUID & uuid,
      std::shared_ptr<const Hunting::Goal> goal)
    {
      RCLCPP_INFO(this->get_logger(), "Received goal request with target %s, catches turtle %s", goal->target_turtle.c_str(),goal->catches_turtle.c_str());
      (void)uuid;
      return rclcpp_action::GoalResponse::ACCEPT_AND_EXECUTE;
    };

    auto handle_cancel = [this](
      const std::shared_ptr<GoalHandleHunting> goal_handle)
    {
      RCLCPP_INFO(this->get_logger(), "Received request to cancel goal");
      (void)goal_handle;
      return rclcpp_action::CancelResponse::ACCEPT;
    };

    auto handle_accepted = [this](
      const std::shared_ptr<GoalHandleHunting> goal_handle)
    {
      // this needs to return quickly to avoid blocking the executor,
      // so we declare a lambda function to be called inside a new thread
      auto execute_in_thread = [this, goal_handle](){return this->execute(goal_handle);};
      std::thread{execute_in_thread}.detach();
    };

    this->action_server_ = rclcpp_action::create_server<Hunting>(
      this,
      "hunting",
      handle_goal,
      handle_cancel,
      handle_accepted);
  }

private:
    rclcpp_action::Server<Hunting>::SharedPtr action_server_;
    rclcpp::Client<turtlesim::srv::TeleportRelative>::SharedPtr teleport_;
    rclcpp::Client<custom_interfaces::srv::Angle>::SharedPtr angle_;
    std::unique_ptr<pluginlib::ClassLoader<polygon_base::RegularPolygon>> poly_loader_;
    std::shared_ptr<polygon_base::RegularPolygon> plugin_length_;
    std::map<std::string,rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr> subscriptions_;
    std::map<std::string,rclcpp::Publisher<geometry_msgs::msg::Twist>::SharedPtr> publishers_;
    std::map<std::string, rclcpp::Client<turtlesim::srv::TeleportRelative>::SharedPtr> teleport_client_;
    std::map<std::string, std::array<float,3>> turtles_coord;
    std::map<std::string, bool> coord_received_;


    void check_teleport(const std::string& name) {
    if (teleport_client_.find(name) == teleport_client_.end()) {
        std::string service_name = "/" + name + "/teleport_relative";
        teleport_client_[name] = this->create_client<turtlesim::srv::TeleportRelative>(service_name);
        RCLCPP_INFO(this->get_logger(), "Created teleport client for %s", service_name.c_str());
    }
}
    void check_sub(const std::string& name){
      if(subscriptions_.find(name)==subscriptions_.end()){
      std::string topic_name = "/"+name+"/pose";
      coord_received_[name] = false;
      subscriptions_[name] = this->create_subscription<turtlesim::msg::Pose>(topic_name,1,
        [this,name](const turtlesim::msg::Pose::SharedPtr msg){
          this->turtles_coord[name]={msg->x,msg->y,msg->theta};
          this->coord_received_[name]=true;
      }
      ); 
      RCLCPP_INFO(this->get_logger(),"Subscribed to topic %s",topic_name.c_str());
      }
    }
    void check_pub(const std::string& name){
        if(publishers_.find(name)==publishers_.end()){
            std::string topic_name = "/"+name+"/cmd_vel";
            publishers_[name] = this->create_publisher<geometry_msgs::msg::Twist>(topic_name,1);
            RCLCPP_INFO(this->get_logger(),"Created publisher for topic %s",topic_name.c_str());
        }
    }
    void publish(const std::string& catches_turtle, const std::string& target_turtle,float length, float angle){
        auto catch_message = geometry_msgs::msg::Twist();
        auto target_message = geometry_msgs::msg::Twist();
        auto tp_request = std::make_shared<turtlesim::srv::TeleportRelative::Request>();
        tp_request->angular = angle;
        teleport_client_[catches_turtle]->async_send_request(tp_request);
        if(length<2.0f){
            catch_message.linear.x  =3.5;
            catch_message.linear.y  =3.5;
        }
       else{
            catch_message.linear.x  =2.0;
            catch_message.linear.y  =2.0;
        }
        if(length<2.0f){
            target_message.linear.x  =3.6;
            target_message.linear.y  =3.6;
            target_message.angular.z =2.0;
        }
        else{
            target_message.linear.x  =7.0;
            target_message.linear.y  =6.0;
            target_message.angular.z =3.0;
        }
        publishers_[catches_turtle]->publish(catch_message);
        publishers_[target_turtle]->publish(target_message);
    }   
    void execute(const std::shared_ptr<GoalHandleHunting> goal_handle) {
        RCLCPP_INFO(this->get_logger(), "Executing goal");
        rclcpp::Rate loop_rate(30);
        const auto goal = goal_handle->get_goal();
        std::string catches = goal->catches_turtle;
        std::string target = goal->target_turtle;
        check_sub(catches);
        check_sub(target);
        check_pub(catches);
        check_pub(target);
        check_teleport(catches);
        auto feedback = std::make_shared<Hunting::Feedback>();
        auto result = std::make_shared<Hunting::Result>();
        
        while(rclcpp::ok()&&(!coord_received_[target] || !coord_received_[catches])){
            RCLCPP_INFO(this->get_logger(),"Waiting for initial poses");
            if (goal_handle->is_canceling()) {
                    goal_handle->canceled(result);
                    return;
            }
            loop_rate.sleep();
        }
        float length =3.0;
        while(rclcpp::ok() &&length>0.2 ) {
            if (goal_handle->is_canceling()) {
                goal_handle->canceled(result);
                RCLCPP_INFO(this->get_logger(), "Goal canceled");
                return;
            }
            plugin_length_->initialize(turtles_coord[target][0],turtles_coord[target][1],turtles_coord[catches][0],turtles_coord[catches][1]);
            length =plugin_length_->length();
            feedback->distance = length;
            auto angle_request = std::make_shared<custom_interfaces::srv::Angle::Request>();
            angle_request->turtle_names[0] = catches;
            angle_request->turtle_names[1] = target;
            auto response = angle_->async_send_request(angle_request);
            float angle = response.get()->angle-turtles_coord[catches][2];
            publish(catches,target,length,angle);
            // Publish feedback
            goal_handle->publish_feedback(feedback);
            RCLCPP_INFO(this->get_logger(), "Publish feedback");
            loop_rate.sleep();
        }

        // Check if goal is done
        if (rclcpp::ok()) {
            result->length = length;
            goal_handle->succeed(result);
            RCLCPP_INFO(this->get_logger(), "Goal succeeded");
        }
    };

};  // class HuntingActionServer

}  // namespace custom_action_cpp

RCLCPP_COMPONENTS_REGISTER_NODE(custom_action_cpp::HuntingActionServer)