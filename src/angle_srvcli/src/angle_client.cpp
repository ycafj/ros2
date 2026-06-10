#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/angle.hpp"

#include <chrono>
#include <cstdlib>
#include <memory>

using namespace std::chrono_literals;

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);
  if (argc != 3) {
        RCLCPP_INFO(rclcpp::get_logger("rclcpp"), 
                "Використання: client name1 name2");
    return 1;
  }
  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("angle_client");
  rclcpp::Client<custom_interfaces::srv::Angle>::SharedPtr client =
    node->create_client<custom_interfaces::srv::Angle>("angle");

  auto request = std::make_shared<custom_interfaces::srv::Angle::Request>();
  for(int i =0;i<2;i++){
    request->turtle_names[i] = argv[i+1]; 
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Got %s",request->turtle_names[i].c_str());
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
    RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Angle between %s and %s : %f(%f in degrees)",request->turtle_names[0].c_str(),request->turtle_names[1].c_str(), result.get()->angle, result.get()->angle*57.29);
  } else {
    RCLCPP_ERROR(rclcpp::get_logger("rclcpp"), "Failed to call service calculate");
  }

  rclcpp::shutdown();
  return 0;
}
