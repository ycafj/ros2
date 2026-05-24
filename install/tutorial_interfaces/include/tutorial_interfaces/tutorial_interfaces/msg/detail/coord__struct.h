// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from tutorial_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

// IWYU pragma: private, include "tutorial_interfaces/msg/coord.h"


#ifndef TUTORIAL_INTERFACES__MSG__DETAIL__COORD__STRUCT_H_
#define TUTORIAL_INTERFACES__MSG__DETAIL__COORD__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

/// Struct defined in msg/Coord in the package tutorial_interfaces.
typedef struct tutorial_interfaces__msg__Coord
{
  float coord[3];
} tutorial_interfaces__msg__Coord;

// Struct for a sequence of tutorial_interfaces__msg__Coord.
typedef struct tutorial_interfaces__msg__Coord__Sequence
{
  tutorial_interfaces__msg__Coord * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} tutorial_interfaces__msg__Coord__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // TUTORIAL_INTERFACES__MSG__DETAIL__COORD__STRUCT_H_
