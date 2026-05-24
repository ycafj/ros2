// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from tutorial_interfaces:msg/Coord.idl
// generated code does not contain a copyright notice

#include "tutorial_interfaces/msg/detail/coord__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_tutorial_interfaces
const rosidl_type_hash_t *
tutorial_interfaces__msg__Coord__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x36, 0xa7, 0x53, 0x6b, 0x45, 0x8d, 0x0b, 0xe9,
      0x62, 0xf2, 0xb2, 0xbc, 0xeb, 0xb9, 0x93, 0x69,
      0xbd, 0x5c, 0xe0, 0x93, 0xf7, 0x39, 0x2f, 0x27,
      0xcb, 0xce, 0xae, 0x2e, 0x63, 0x40, 0x35, 0x35,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types

// Hashes for external referenced types
#ifndef NDEBUG
#endif

static char tutorial_interfaces__msg__Coord__TYPE_NAME[] = "tutorial_interfaces/msg/Coord";

// Define type names, field names, and default values
static char tutorial_interfaces__msg__Coord__FIELD_NAME__coord[] = "coord";

static rosidl_runtime_c__type_description__Field tutorial_interfaces__msg__Coord__FIELDS[] = {
  {
    {tutorial_interfaces__msg__Coord__FIELD_NAME__coord, 5, 5},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_FLOAT_ARRAY,
      3,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
tutorial_interfaces__msg__Coord__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {tutorial_interfaces__msg__Coord__TYPE_NAME, 29, 29},
      {tutorial_interfaces__msg__Coord__FIELDS, 1, 1},
    },
    {NULL, 0, 0},
  };
  if (!constructed) {
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "float32[3] coord";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
tutorial_interfaces__msg__Coord__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {tutorial_interfaces__msg__Coord__TYPE_NAME, 29, 29},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 17, 17},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
tutorial_interfaces__msg__Coord__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[1];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 1, 1};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *tutorial_interfaces__msg__Coord__get_individual_type_description_source(NULL),
    constructed = true;
  }
  return &source_sequence;
}
