#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/calculate.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  if (argc != 4) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
                "Використання: client name1 name2 name3");
    return 1;
  }
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("calculate_client");
  rclcpp::Client<custom_interfaces::srv::Calculate>::SharedPtr client =
    node->create_client<custom_interfaces::srv::Calculate>("calculate");

  auto request = std::make_shared<custom_interfaces::srv::Calculate::Request>();
  for(int i =0;i<3;i++){
    request->turtles[i] = argv[i+1]; 
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Got %s",request->turtles[i].c_str());
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
