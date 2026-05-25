#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/coord.hpp"

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

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
  return 0;
}
