#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/calculate.hpp"
#include "turtlesim/msg/pose.hpp"
#include <memory>
#include <map>

class CalculateServer : public rclcpp::Node
{
  public:
    CalculateServer() : Node("calculate_server")
    {
      service_ = this->create_service<custom_interfaces::srv::Calculate>("calculate",std::bind(&CalculateServer::calculate, this, std::placeholders::_1, std::placeholders::_2));
      RCLCPP_INFO(this->get_logger(), "Ready to calculate");
    }
  private:
    std::map<std::string, float> turtles_y_coord;
    std::map<std::string,rclcpp::Subscription<turtlesim::msg::Pose>::SharedPtr> subscriptions_;
    rclcpp::Service<custom_interfaces::srv::Calculate>::SharedPtr service_;

void check_sub(const std::string& name){
  if(subscriptions_.find(name)==subscriptions_.end()){
    std::string topic_name = "/"+name+"/pose";
    subscriptions_[name] = this->create_subscription<turtlesim::msg::Pose>(topic_name,10,
      [this,name](const turtlesim::msg::Pose::SharedPtr msg){
        this->turtles_y_coord[name]=msg->y;
      }
    ); 
    RCLCPP_INFO(this->get_logger(),"Subscribed to topic %s",topic_name.c_str());
  }
}
void calculate(const std::shared_ptr<custom_interfaces::srv::Calculate::Request> request,
          std::shared_ptr<custom_interfaces::srv::Calculate::Response>      response)
{
  if(request->turtles.empty()){
    RCLCPP_WARN(this->get_logger(),"Empty turtle names list");
    return;
  }
  float maxY=-1.0;
  std::string max_name="";
  for(size_t i=0;i<request->turtles.size();i++){
    std::string name = request->turtles[i];
    check_sub(name);
    if(turtles_y_coord.find(name)!=turtles_y_coord.end()){
      float cur_y = turtles_y_coord[name];
      if(cur_y>maxY){
        maxY = cur_y;
        max_name = name;
      }
      RCLCPP_INFO(this->get_logger(), "TUrtle %s have Y: %f", name.c_str(), cur_y);
    }
    
  }
  response->name = max_name;
  RCLCPP_INFO(this->get_logger(), "Max Y: %f, turtle: %s",
  maxY, response->name.c_str());
}
};
int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<CalculateServer>());
  rclcpp::shutdown();
}
