// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from custom_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#include "custom_interfaces/msg/detail/coord__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_custom_interfaces
const rosidl_type_hash_t *
custom_interfaces__msg__Coord__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x5a, 0x0a, 0x62, 0x00, 0xa9, 0x99, 0x9a, 0x69,
      0xc4, 0x71, 0x96, 0x44, 0x4c, 0xcf, 0x82, 0xfa,
      0x3d, 0x1d, 0xc9, 0xcb, 0x0d, 0x01, 0xb5, 0x1f,
      0x5e, 0x83, 0x1b, 0x2a, 0xcb, 0x03, 0x4c, 0x7b,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char custom_interfaces__msg__Coord__TYPE_NAME[] = "custom_interfaces/msg/Coord";

// Define type names, field names, and default values
static char custom_interfaces__msg__Coord__FIELD_NAME__x[] = "x";
static char custom_interfaces__msg__Coord__FIELD_NAME__y[] = "y";
static char custom_interfaces__msg__Coord__FIELD_NAME__theta[] = "theta";
static char custom_interfaces__msg__Coord__FIELD_NAME__name[] = "name";

static rosidl_runtime_c__type_description__Field custom_interfaces__msg__Coord__FIELDS[] = {
  {
    {custom_interfaces__msg__Coord__FIELD_NAME__x, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__Coord__FIELD_NAME__y, 1, 1},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__Coord__FIELD_NAME__theta, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {custom_interfaces__msg__Coord__FIELD_NAME__name, 4, 4},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
custom_interfaces__msg__Coord__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {custom_interfaces__msg__Coord__TYPE_NAME, 27, 27},
      {custom_interfaces__msg__Coord__FIELDS, 4, 4},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32 x\n"
  "float32 y\n"
  "float32 theta\n"
  "string name";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
custom_interfaces__msg__Coord__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {custom_interfaces__msg__Coord__TYPE_NAME, 27, 27},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 46, 46},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
custom_interfaces__msg__Coord__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *custom_interfaces__msg__Coord__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
