// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from tutorial_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tutorial_interfaces/msg/coord.hpp"


#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__COORD__STRUCT_HPP_
#define TUTORIAL_INTERFACES__MSG__DETAIL__COORD__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <cstdint>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


#ifndef _WIN32
# define DEPRECATED__tutorial_interfaces__msg__Coord __attribute__((deprecated))
#else
# define DEPRECATED__tutorial_interfaces__msg__Coord __declspec(deprecated)
#endif

namespace tutorial_interfaces
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct Coord_
{
  using Type = Coord_<ContainerAllocator>;

  explicit Coord_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->coord.begin(), this->coord.end(), 0.0f);
    }
  }

  explicit Coord_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : coord(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      std::fill<typename std::array<float, 3>::iterator, float>(this->coord.begin(), this->coord.end(), 0.0f);
    }
  }

  // field types and members
  using _coord_type =
    std::array<float, 3>;
  _coord_type coord;

  // setters for named parameter idiom
  Type & set__coord(
    const std::array<float, 3> & _arg)
  {
    this->coord = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    tutorial_interfaces::msg::Coord_<ContainerAllocator> *;
  using ConstRawPtr =
    const tutorial_interfaces::msg::Coord_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::Coord_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      tutorial_interfaces::msg::Coord_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__tutorial_interfaces__msg__Coord
    std::shared_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__tutorial_interfaces__msg__Coord
    std::shared_ptr<tutorial_interfaces::msg::Coord_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const Coord_ & other) const
  {
    if (this->coord != other.coord) {
      return false;
    }
    return true;
  }
  bool operator!=(const Coord_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct Coord_

// alias to use template instance with default allocator
using Coord =
  tutorial_interfaces::msg::Coord_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace tutorial_interfaces

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__COORD__STRUCT_HPP_
