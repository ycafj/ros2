// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from tutorial_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tutorial_interfaces/msg/coord.hpp"


#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "tutorial_interfaces/msg/detail/coord__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace tutorial_interfaces
{

namespace msg
{

namespace builder
{

class Init_Coord_coord
{
public:
  Init_Coord_coord()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::tutorial_interfaces::msg::Coord coord(::tutorial_interfaces::msg::Coord::_coord_type arg)
  {
    msg_.coord = std::move(arg);
    return std::move(msg_);
  }

private:
  ::tutorial_interfaces::msg::Coord msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::tutorial_interfaces::msg::Coord>()
{
  return tutorial_interfaces::msg::builder::Init_Coord_coord();
}

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__COORD__BUILDER_HPP_
