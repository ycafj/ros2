#include "rclcpp/rclcpp.hpp"
#include "rclcpp_components/register_node_macro.hpp"
#include "custom_interfaces/srv/angle.hpp"
#include "turtlesim/msg/pose.hpp"
#include <memory>
#include <map>
#include <cmath>
#include <pluginlib/class_loader.hpp>
#include <polygon_base/regular_polygon.hpp>

#define PI 3.14159265
namespace angle_srvcli{
class AngleServer : public rclcpp::Node
{
  public:
    AngleServer(const rclcpp::NodeOptions & options) : Node("angle_server",options)
    {
      service_ = this->create_service<custom_interfaces::srv::Angle>("angle",std::bind(&AngleServer::calculate, this, std::placeholders::_1, std::placeholders::_2));
      RCLCPP_INFO(this->get_logger(), "Ready to calculate angle");
      try {
      poly_loader_ = std::make_unique<pluginlib::ClassLoader<polygon_base::RegularPolygon>>(
        "polygon_base", "polygon_base::RegularPolygon");
      plugin_length_ = poly_loader_->createSharedInstance("polygon_plugins::Length");
      RCLCPP_INFO(this->get_logger(), "Плагін успішно завантажено.");
      }
      catch (pluginlib::PluginlibException& ex) {
        RCLCPP_ERROR(this->get_logger(), "Не вдалося завантажити плагін: %s", ex.what());
      } 
    }
  private:
    
    std::map<std::string,rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr> subscriptions_;
    rclcpp::Service<custom_interfaces::srv::Angle>::SharedPtr service_;
    rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr subscription_;
    std::unique_ptr<pluginlib::ClassLoader<polygon_base::RegularPolygon>> poly_loader_;
    std::shared_ptr<polygon_base::RegularPolygon> plugin_length_;
    std::map<std::string, std::array<float,2>> turtles_coord;
    
    void check_sub(const std::string& name){
      if(subscriptions_.find(name)==subscriptions_.end()){
      std::string topic_name = "/"+name+"/pose";
      subscriptions_[name] = this->create_subscription<turtlesim::msg::Pose>(topic_name,10,
        [this,name](const turtlesim::msg::Pose::SharedPtr msg){
          this->turtles_coord[name]={msg->x,msg->y};
      }
      ); 
      RCLCPP_INFO(this->get_logger(),"Subscribed to topic %s",topic_name.c_str());
      }
    }
    
    void calculate(const std::shared_ptr<custom_interfaces::srv::Angle::Request> request,
      std::shared_ptr<custom_interfaces::srv::Angle::Response> response)
    {
      if(request->turtle_names.empty()){
        RCLCPP_WARN(this->get_logger(),"Empty turtle names list");
        return;
      }
      std::string turtle1 = request->turtle_names[0];
      check_sub(turtle1);
      std::string turtle2 = request->turtle_names[1];
      check_sub(turtle2);
      RCLCPP_INFO(this->get_logger(),"X %f Y %f X %f Y %f",turtles_coord[turtle1][0],turtles_coord[turtle1][1],turtles_coord[turtle2][0],turtles_coord[turtle2][1]);
      plugin_length_->initialize(turtles_coord[turtle2][0], turtles_coord[turtle2][1], turtles_coord[turtle2][0], turtles_coord[turtle1][1]);
      float katet1 = plugin_length_->length();
      plugin_length_->initialize(turtles_coord[turtle1][0], turtles_coord[turtle1][1], turtles_coord[turtle2][0], turtles_coord[turtle1][1]);
      float katet2 = plugin_length_->length();
      float response_ = std::atan2(katet1,katet2);
      if(turtles_coord[turtle1][0]>turtles_coord[turtle2][0]){
        response_ = abs(PI-response_);
      }
      if(turtles_coord[turtle1][1]>turtles_coord[turtle2][1]){
        response_*=-1;
      }
      response->angle = response_;
      RCLCPP_INFO(this->get_logger(), "Angle: %f(%f in degrees),from turtle %s to turtle %s",
      response->angle,response->angle*57.29, turtle1.c_str(),turtle2.c_str());
    }
};
}
RCLCPP_COMPONENTS_REGISTER_NODE(angle_srvcli::AngleServer)