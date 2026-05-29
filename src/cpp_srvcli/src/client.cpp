#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/calculate.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("calculate_client");
  rclcpp::Client<custom_interfaces::srv::Calculate>::SharedPtr client =
    node->create_client<custom_interfaces::srv::Calculate>("calculate");

  auto request = std::make_shared<custom_interfaces::srv::Calculate::Request>();
    request->turtles[0].x = std::stof(argv[1]);
    request->turtles[0].y = std::stof(argv[2]);
    request->turtles[0].theta = std::stof(argv[3]);
    request->turtles[0].name = argv[4]; 

    request->turtles[1].x = std::stof(argv[5]);
    request->turtles[1].y = std::stof(argv[6]);
    request->turtles[1].theta = std::stof(argv[7]);
    request->turtles[1].name = argv[8];

    request->turtles[2].x = std::stof(argv[9]);
    request->turtles[2].y = std::stof(argv[10]);
    request->turtles[2].theta = std::stof(argv[11]);
    request->turtles[2].name = argv[12];

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
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service add_two_ints");
  }

  rclcpp::shutdown();
  return 0;
}
