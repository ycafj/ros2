#include <chrono>
#include <memory>

#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/coord.hpp"
#include "turtlesim/srv/teleport_absolute.hpp" 

using namespace std::chrono_literals;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("subscriber")
  {
    client_ = this->create_client<turtlesim::srv::TeleportAbsolute>("turtle1/teleport_absolute");
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

    RCLCPP_INFO(this->get_logger(), "Відправляємо запит на телепортацію...");
    client_->async_send_request(request,
      [this](rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedFuture future) {
        try {
          auto response = future.get();
          RCLCPP_INFO(this->get_logger(), "Черепаху успішно телепортовано!");
        } catch (const std::exception &e) {
          RCLCPP_ERROR(this->get_logger(), "Помилка телепортації: %s", e.what());
        }
      }
    );
  }
private:
  rclcpp::Subscription<custom_interfaces::msg::Coord>::SharedPtr subscription_;
  rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr client_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
