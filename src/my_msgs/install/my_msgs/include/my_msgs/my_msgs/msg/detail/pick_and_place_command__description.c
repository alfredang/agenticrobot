// generated from rosidl_generator_c/resource/idl__description.c.em
// with input from my_msgs:msg/PickAndPlaceCommand.idl
// generated code does not contain a copyright notice

#include "my_msgs/msg/detail/pick_and_place_command__functions.h"

ROSIDL_GENERATOR_C_PUBLIC_my_msgs
const rosidl_type_hash_t *
my_msgs__msg__PickAndPlaceCommand__get_type_hash(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_type_hash_t hash = {1, {
      0x17, 0x9c, 0x15, 0x4a, 0x5e, 0xdd, 0x8d, 0x63,
      0xb9, 0x5f, 0x01, 0x92, 0x02, 0x3a, 0x41, 0xf1,
      0x1c, 0xfd, 0xa5, 0xe2, 0xc1, 0x3f, 0x99, 0xe5,
      0xa0, 0x27, 0xab, 0xef, 0xd1, 0x19, 0xf5, 0xa6,
    }};
  return &hash;
}

#include <assert.h>
#include <string.h>

// Include directives for referenced types
#include "geometry_msgs/msg/detail/point__functions.h"

// Hashes for external referenced types
#ifndef NDEBUG
static const rosidl_type_hash_t geometry_msgs__msg__Point__EXPECTED_HASH = {1, {
    0x69, 0x63, 0x08, 0x48, 0x42, 0xa9, 0xb0, 0x44,
    0x94, 0xd6, 0xb2, 0x94, 0x1d, 0x11, 0x44, 0x47,
    0x08, 0xd8, 0x92, 0xda, 0x2f, 0x4b, 0x09, 0x84,
    0x3b, 0x9c, 0x43, 0xf4, 0x2a, 0x7f, 0x68, 0x81,
  }};
#endif

static char my_msgs__msg__PickAndPlaceCommand__TYPE_NAME[] = "my_msgs/msg/PickAndPlaceCommand";
static char geometry_msgs__msg__Point__TYPE_NAME[] = "geometry_msgs/msg/Point";

// Define type names, field names, and default values
static char my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__command_type[] = "command_type";
static char my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__object_id[] = "object_id";
static char my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__left_to_right[] = "left_to_right";
static char my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__target_position[] = "target_position";

static rosidl_runtime_c__type_description__Field my_msgs__msg__PickAndPlaceCommand__FIELDS[] = {
  {
    {my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__command_type, 12, 12},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__object_id, 9, 9},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_STRING,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__left_to_right, 13, 13},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_BOOLEAN,
      0,
      0,
      {NULL, 0, 0},
    },
    {NULL, 0, 0},
  },
  {
    {my_msgs__msg__PickAndPlaceCommand__FIELD_NAME__target_position, 15, 15},
    {
      rosidl_runtime_c__type_description__FieldType__FIELD_TYPE_NESTED_TYPE,
      0,
      0,
      {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    },
    {NULL, 0, 0},
  },
};

static rosidl_runtime_c__type_description__IndividualTypeDescription my_msgs__msg__PickAndPlaceCommand__REFERENCED_TYPE_DESCRIPTIONS[] = {
  {
    {geometry_msgs__msg__Point__TYPE_NAME, 23, 23},
    {NULL, 0, 0},
  },
};

const rosidl_runtime_c__type_description__TypeDescription *
my_msgs__msg__PickAndPlaceCommand__get_type_description(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static bool constructed = false;
  static const rosidl_runtime_c__type_description__TypeDescription description = {
    {
      {my_msgs__msg__PickAndPlaceCommand__TYPE_NAME, 31, 31},
      {my_msgs__msg__PickAndPlaceCommand__FIELDS, 4, 4},
    },
    {my_msgs__msg__PickAndPlaceCommand__REFERENCED_TYPE_DESCRIPTIONS, 1, 1},
  };
  if (!constructed) {
    assert(0 == memcmp(&geometry_msgs__msg__Point__EXPECTED_HASH, geometry_msgs__msg__Point__get_type_hash(NULL), sizeof(rosidl_type_hash_t)));
    description.referenced_type_descriptions.data[0].fields = geometry_msgs__msg__Point__get_type_description(NULL)->type_description.fields;
    constructed = true;
  }
  return &description;
}

static char toplevel_type_raw_source[] =
  "# my_msgs/msg/PickAndPlaceCommand.msg\n"
  "string command_type             # \"pick_all\", \"pick_specific\", or \"count_objects\"\n"
  "string object_id                # ID of the specific object to pick\n"
  "bool left_to_right              # Direction for pick_all command (false for left to right, true for right to left)\n"
  "geometry_msgs/Point target_position  # Position to place the object";

static char msg_encoding[] = "msg";

// Define all individual source functions

const rosidl_runtime_c__type_description__TypeSource *
my_msgs__msg__PickAndPlaceCommand__get_individual_type_description_source(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static const rosidl_runtime_c__type_description__TypeSource source = {
    {my_msgs__msg__PickAndPlaceCommand__TYPE_NAME, 31, 31},
    {msg_encoding, 3, 3},
    {toplevel_type_raw_source, 371, 371},
  };
  return &source;
}

const rosidl_runtime_c__type_description__TypeSource__Sequence *
my_msgs__msg__PickAndPlaceCommand__get_type_description_sources(
  const rosidl_message_type_support_t * type_support)
{
  (void)type_support;
  static rosidl_runtime_c__type_description__TypeSource sources[2];
  static const rosidl_runtime_c__type_description__TypeSource__Sequence source_sequence = {sources, 2, 2};
  static bool constructed = false;
  if (!constructed) {
    sources[0] = *my_msgs__msg__PickAndPlaceCommand__get_individual_type_description_source(NULL),
    sources[1] = *geometry_msgs__msg__Point__get_individual_type_description_source(NULL);
    constructed = true;
  }
  return &source_sequence;
}
