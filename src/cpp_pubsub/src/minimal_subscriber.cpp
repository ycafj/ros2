#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/coord.hpp"
#include "turtlesim/srv/teleport_absolute.hpp" 
#include "turtlesim/srv/spawn.hpp"
using namespace std::chrono_literals;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("subscriber"),turtlenum_()
  {
    spawn_ = this->create_client<turtlesim::srv::Spawn>("spawn");
    
    subscription_ = this->create_subscription<custom_interfaces::msg::Coord>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1));
  }
  void topic_callback(const custom_interfaces::msg::Coord::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Отримано координати: x:%f, y:%f, theta:%f", msg->x, msg->y, msg->theta);
    auto request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    request->x = msg->x;
    request->y = msg->y;
    request->theta = msg->theta;
    
    if(turtlenum_<4){
      turtlenum_++;
      auto param = std::make_shared<turtlesim::srv::Spawn::Request>();
      param->x = msg->x;
      param->y = msg->y;
      param->theta = msg->theta;
      param->name = msg->name;
      spawn_->async_send_request(param);
    }
    RCLCPP_INFO(this->get_logger(), "Відправляємо запит на телепортацію...");
    teleport_ = this->create_client<turtlesim::srv::TeleportAbsolute>(msg->name+"/teleport_absolute");
    teleport_->async_send_request(request);
  }
 
private:
  rclcpp::Subscription<custom_interfaces::msg::Coord>::SharedPtr subscription_;
  rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr teleport_;
  rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr spawn_;
  size_t turtlenum_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
