// generated from rosidl_generator_cpp/resource/idl__traits.hpp.em
// with input from tutorial_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tutorial_interfaces/msg/coord.hpp"


#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__COORD__TRAITS_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__COORD__TRAITS_HPP_

#include <stdint.h>

#include <sstream>
#include <string>
#include <type_traits>

#include "tutorial_interfaces/msg/detail/coord__struct.hpp"
#include "rosidl_runtime_cpp/traits.hpp"

namespace tutorial_interfaces
{

namespace msg
{

inline void to_flow_style_yaml(
  const Coord & msg,
  std::ostream & out)
{
  out << "{";
  // member: coord
  {
    if (msg.coord.size() == 0) {
      out << "coord: []";
    } else {
      out << "coord: [";
      size_t pending_items = msg.coord.size();
      for (auto item : msg.coord) {
        rosidl_generator_traits::value_to_yaml(item, out);
        if (--pending_items > 0) {
          out << ", ";
        }
      }
      out << "]";
    }
  }
  out << "}";
}  // NOLINT(readability/fn_size)

inline void to_block_style_yaml(
  const Coord & msg,
  std::ostream & out, size_t indentation = 0)
{
  // member: coord
  {
    if (indentation > 0) {
      out << std::string(indentation, ' ');
    }
    if (msg.coord.size() == 0) {
      out << "coord: []\n";
    } else {
      out << "coord:\n";
      for (auto item : msg.coord) {
        if (indentation > 0) {
          out << std::string(indentation, ' ');
        }
        out << "- ";
        rosidl_generator_traits::value_to_yaml(item, out);
        out << "\n";
      }
    }
  }
}  // NOLINT(readability/fn_size)

inline std::string to_yaml(const Coord & msg, bool use_flow_style = false)
{
  std::ostringstream out;
  if (use_flow_style) {
    to_flow_style_yaml(msg, out);
  } else {
    to_block_style_yaml(msg, out);
  }
  return out.str();
}

}  // namespace msg

}  // namespace tutorial_interfaces

namespace rosidl_generator_traits
{

[[deprecated("use tutorial_interfaces::msg::to_block_style_yaml() instead")]]
inline void to_yaml(
  const tutorial_interfaces::msg::Coord & msg,
  std::ostream & out, size_t indentation = 0)
{
  tutorial_interfaces::msg::to_block_style_yaml(msg, out, indentation);
}

[[deprecated("use tutorial_interfaces::msg::to_yaml() instead")]]
inline std::string to_yaml(const tutorial_interfaces::msg::Coord & msg)
{
  return tutorial_interfaces::msg::to_yaml(msg);
}

template<>
inline const char * data_type<tutorial_interfaces::msg::Coord>()
{
  return "tutorial_interfaces::msg::Coord";
}

template<>
inline const char * name<tutorial_interfaces::msg::Coord>()
{
  return "tutorial_interfaces/msg/Coord";
}

template<>
struct has_fixed_size<tutorial_interfaces::msg::Coord>
  : std::integral_constant<bool, true> {};

template<>
struct has_bounded_size<tutorial_interfaces::msg::Coord>
  : std::integral_constant<bool, true> {};

template<>
struct is_message<tutorial_interfaces::msg::Coord>
  : std::true_type {};

}  // namespace rosidl_generator_traits

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__COORD__TRAITS_HPP_
