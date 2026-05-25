// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from custom_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "custom_interfaces/msg/coord.hpp"


#ifndef CUSTOM_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
#define CUSTOM_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "custom_interfaces/msg/detail/coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace custom_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coord_name
{
public:
  explicit Init_Coord_name(::custom_interfaces::msg::Coord & msg)
  : msg_(msg)
  {}
  ::custom_interfaces::msg::Coord name(::custom_interfaces::msg::Coord::_name_type arg)
  {
    msg_.name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::custom_interfaces::msg::Coord msg_;
};

class Init_Coord_theta
{
public:
  explicit Init_Coord_theta(::custom_interfaces::msg::Coord & msg)
  : msg_(msg)
  {}
  Init_Coord_name theta(::custom_interfaces::msg::Coord::_theta_type arg)
  {
    msg_.theta = std::move(arg);
    return Init_Coord_name(msg_);
  }

private:
  ::custom_interfaces::msg::Coord msg_;
};

class Init_Coord_y
{
public:
  explicit Init_Coord_y(::custom_interfaces::msg::Coord & msg)
  : msg_(msg)
  {}
  Init_Coord_theta y(::custom_interfaces::msg::Coord::_y_type arg)
  {
    msg_.y = std::move(arg);
    return Init_Coord_theta(msg_);
  }

private:
  ::custom_interfaces::msg::Coord msg_;
};

class Init_Coord_x
{
public:
  Init_Coord_x()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_Coord_y x(::custom_interfaces::msg::Coord::_x_type arg)
  {
    msg_.x = std::move(arg);
    return Init_Coord_y(msg_);
  }

private:
  ::custom_interfaces::msg::Coord msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::custom_interfaces::msg::Coord>()
{
  return custom_interfaces::msg::builder::Init_Coord_x();
}

}  // namespace custom_interfaces

#endif  // CUSTOM_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
