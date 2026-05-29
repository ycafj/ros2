#include "rclcpp/rclcpp.hpp"
#include "custom_interfaces/srv/calculate.hpp"

#include <memory>

void calculate(const std::shared_ptr<custom_interfaces::srv::Calculate::Request> request,
          std::shared_ptr<custom_interfaces::srv::Calculate::Response>      response)
{
  int pos,maxY=0;
  for(size_t i=0;i<request->turtles.size();i++){
    if(request->turtles[i].y>maxY) {
        maxY=request->turtles[i].y;
        pos=i;
    }
  }
  response->name = request->turtles[pos].name;
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Incoming request\na: %s",
                request->turtles[pos].name.c_str());
  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "sending back response: [%s]",response->name.c_str());
}

int main(int argc, char **argv)
{
  rclcpp::init(argc, argv);

  std::shared_ptr<rclcpp::Node> node = rclcpp::Node::make_shared("calculate_server");

  rclcpp::Service<custom_interfaces::srv::Calculate>::SharedPtr service =
  node->create_service<custom_interfaces::srv::Calculate>("calculate", &calculate);

  RCLCPP_INFO(rclcpp::get_logger("rclcpp"), "Ready to calculate.");

  rclcpp::spin(node);
  rclcpp::shutdown();
}
