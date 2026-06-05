#include <chrono>
#include <memory>
#include <string>
#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/msg/coord.hpp"
#include "turtlesim/srv/teleport_absolute.hpp" 
#include "turtlesim/srv/spawn.hpp"
#include <pluginlib/class_loader.hpp>
#include <polygon_base/regular_polygon.hpp>

using namespace std::chrono_literals;

class MinimalSubscriber : public rclcpp::Node
{
public:
  MinimalSubscriber()
  : Node("subscriber"),turtlenum_(1)
  {
    spawn_ = this->create_client<turtlesim::srv::Spawn>("spawn");
    subscription_ = this->create_subscription<custom_interfaces::msg::Coord>(
      "topic", 10, std::bind(&MinimalSubscriber::topic_callback, this, std::placeholders::_1));
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
  
  void topic_callback(const custom_interfaces::msg::Coord::SharedPtr msg)
  {
    RCLCPP_INFO(this->get_logger(), "Отримано координати: x:%f, y:%f, theta:%f від %s", msg->x, msg->y, msg->theta, msg->name.c_str());
    turtles_coords_[msg->name] = *msg;
   std::string previous_turtle_name = "";
    if (msg->name == "aboba1") {
      previous_turtle_name = "aboba0";
    } else if (msg->name == "aboba2") {
      previous_turtle_name = "aboba1";
    } else if (msg->name == "aboba0") {
      previous_turtle_name = "aboba2";
    }
    if (plugin_length_ && !previous_turtle_name.empty()) {
      if (turtles_coords_.find(previous_turtle_name) != turtles_coords_.end()) {
        auto prev_coord = turtles_coords_[previous_turtle_name];
        plugin_length_->initialize(prev_coord.x, prev_coord.y, msg->x, msg->y);
        double distance = plugin_length_->length();
        RCLCPP_INFO(this->get_logger(), "Відстань між %s та %s : %f", 
        previous_turtle_name.c_str(), msg->name.c_str(), distance);
      } else {
        RCLCPP_INFO(this->get_logger(), "Попередня черепаха (%s) ще не надіслала своїх координат.", 
        previous_turtle_name.c_str());
      }
    }
    teleport_ = this->create_client<turtlesim::srv::TeleportAbsolute>(msg->name+"/teleport_absolute");
    auto request = std::make_shared<turtlesim::srv::TeleportAbsolute::Request>();
    request->x = msg->x;
    request->y = msg->y;
    request->theta = msg->theta;
    
    if(turtlenum_<=3){
      ++turtlenum_;
      auto param = std::make_shared<turtlesim::srv::Spawn::Request>();
      param->x = msg->x;
      param->y = msg->y;
      param->theta = msg->theta;
      param->name = msg->name;
      spawn_->async_send_request(param);
    }
    RCLCPP_INFO(this->get_logger(), "Відправляємо запит на телепортацію...");
    teleport_->async_send_request(request);
    RCLCPP_INFO(this->get_logger(), "Черепаху успішно телепортовано");
  }
 
private:

  rclcpp::Subscription<custom_interfaces::msg::Coord>::SharedPtr subscription_;
  rclcpp::Client<turtlesim::srv::TeleportAbsolute>::SharedPtr teleport_;
  rclcpp::Client<turtlesim::srv::Spawn>::SharedPtr spawn_;
  size_t turtlenum_;
  std::unique_ptr<pluginlib::ClassLoader<polygon_base::RegularPolygon>> poly_loader_;
  std::shared_ptr<polygon_base::RegularPolygon> plugin_length_;
  std::map<std::string, custom_interfaces::msg::Coord> turtles_coords_;
};

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}
