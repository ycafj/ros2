#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/calculate.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  if (argc != 13) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
                "Використання: client x1 y1 th1 name1 x2 y2 th2 name2 x3 y3 th3 name3");
    return 1;
  }
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("calculate_client");
  rclcpp::Client<custom_interfaces::srv::Calculate>::SharedPtr client =
    node->create_client<custom_interfaces::srv::Calculate>("calculate");

  auto request = std::make_shared<custom_interfaces::srv::Calculate::Request>();
  for(int i =0;i<3;i++){
    request->turtles[i].x = std::stof(argv[1+(i*4)]);
    request->turtles[i].y = std::stof(argv[2+(i*4)]);
    request->turtles[i].theta = std::stof(argv[3+(i*4)]);
    request->turtles[i].name = argv[4+(i*4)]; 
  }
  while (!client->wait_for_service(1s)) {
    if (!rclcpp::ok()) {
      RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Interrupted while waiting for the service. Exiting.");
      return 0;
    }
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "service not available, waiting again...");
  }

  auto result = client->async_send_request(request);

  if (rclcpp::spin_until_future_complete(node, result) ==
    rclcpp::FutureReturnCode::SUCCESS)
  {
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Top turtle: %s", result.get()->name.c_str());
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service calculate");
  }

  rclcpp::shutdown();
  return 0;
}
