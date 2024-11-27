// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from my_msgs:msg/PickAndPlaceCommand.idl
// generated code does not contain a copyright notice

#ifndef MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__STRUCT_H_
#define MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

// Constants defined in the message

// Include directives for member types
// Member 'command_type'
// Member 'object_id'
#include "rosidl_runtime_c/string.h"
// Member 'target_position'
#include "geometry_msgs/msg/detail/point__struct.h"

/// Struct defined in msg/PickAndPlaceCommand in the package my_msgs.
/**
  * my_msgs/msg/PickAndPlaceCommand.msg
 */
typedef struct my_msgs__msg__PickAndPlaceCommand
{
  /// "pick_all", "pick_specific", or "count_objects"
  rosidl_runtime_c__String command_type;
  /// ID of the specific object to pick
  rosidl_runtime_c__String object_id;
  /// Direction for pick_all command (false for left to right, true for right to left)
  bool left_to_right;
  /// Position to place the object
  geometry_msgs__msg__Point target_position;
} my_msgs__msg__PickAndPlaceCommand;

// Struct for a sequence of my_msgs__msg__PickAndPlaceCommand.
typedef struct my_msgs__msg__PickAndPlaceCommand__Sequence
{
  my_msgs__msg__PickAndPlaceCommand * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} my_msgs__msg__PickAndPlaceCommand__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__STRUCT_H_
