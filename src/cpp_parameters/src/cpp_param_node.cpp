#include <chrono>
#include <functional>
#include <string>
#include <rclcpp/rclcpp.hpp>

using namespace std::chrono_literals;

class MinimalParam : public rclcpp::Node
{
public:
  MinimalParam()
  : Node("turtlesim_node")
  {
    this->declare_parameter("background_r", 20);

    auto timer_callback = [this](){
      //rclcpp::Parameter param_r = this->get_parameter("background_r").as_int();
      //int my_param = param_r.as_int();
      int my_param = this->get_parameter("background_r").as_int();
      
      my_param+=50;
      RCLCPP_INFO(this->get_logger(), "Red: %i", my_param);
      
      std::vector<rclcpp::Parameter> all_new_parameters{rclcpp::Parameter("background_r", my_param)};
      this->set_parameters(all_new_parameters);
      my_param+=50;
      if(my_param>200) my_param = 0;
    };
    timer_ = this->create_wall_timer(2000ms, timer_callback);
  }

private:
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char ** argv)
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalParam>());
  rclcpp::shutdown();
  return 0;
}
