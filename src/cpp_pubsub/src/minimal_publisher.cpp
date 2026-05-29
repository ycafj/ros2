#include <chrono>
#include <memory>
#include <map>
#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/coord.hpp"
#include "custom_interfaces/srv/calculate.hpp"

using namespace std::chrono_literals;
class MinimalPublisher : public rclcpp::Node
{
public:
  MinimalPublisher()
  : Node("publisher"), count_()
  {
    publisher_ = this->create_publisher<custom_interfaces::msg::Coord>("topic", 10);
    auto timer_callback =
      [this]() -> void {
        count_++;
        auto message = custom_interfaces::msg::Coord();
        message.x = (count_+2)%3+4;
        message.y = (count_+3)%5+1;
        message.theta = (count_+1)%4;
        message.name = "aboba"+std::to_string(count_%3);
        if(count_ >=20) count_=0;
        RCLCPP_INFO(this->get_logger(), "Публікую координати: x:%f, y:%f, theta:%f", message.x,message.y,message.theta);
        this->publisher_->publish(message);
      };
    timer_ = this->create_wall_timer(2000ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<custom_interfaces::msg::Coord>::SharedPtr publisher_;
  size_t count_;
};
/*void calculate(const std::shared_ptr<custom_interfaces::srv::Calculate::Request> request, std::shared_ptr<custom_interfaces::srv::Response> response)
{
  std::map<int,int> coord_Y;
  for(int i=0;i<request->turtles.size();i++){
    coord_Y[i] = request->turtles[i].y;
  }
  int maxY=0;
  for(int i=0;i<request->turtles.size();i++){
    if( request->turtles[i].y>maxY)maxY = request->turtles[i].y;
  }
  
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\nx: %f y: %f name: %s",request->turtles, request->b);
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%ld]", (long int)response->sum);
}
}
*/
int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
