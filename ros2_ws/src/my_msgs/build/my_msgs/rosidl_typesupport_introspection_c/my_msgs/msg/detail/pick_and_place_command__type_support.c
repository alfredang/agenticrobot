// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from my_msgs:msg/PickAndPlaceCommand.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "my_msgs/msg/detail/pick_and_place_command__rosidl_typesupport_introspection_c.h"
#include "my_msgs/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "my_msgs/msg/detail/pick_and_place_command__functions.h"
#include "my_msgs/msg/detail/pick_and_place_command__struct.h"


// Include directives for member types
// Member `command_type`
// Member `object_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `target_position`
#include "geometry_msgs/msg/point.h"
// Member `target_position`
#include "geometry_msgs/msg/detail/point__rosidl_typesupport_introspection_c.h"

#ifdef __cplusplus
extern "C"
{
#endif

void my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  my_msgs__msg__PickAndPlaceCommand__init(message_memory);
}

void my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_fini_function(void * message_memory)
{
  my_msgs__msg__PickAndPlaceCommand__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_member_array[4] = {
  {
    "command_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgs__msg__PickAndPlaceCommand, command_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "object_id",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgs__msg__PickAndPlaceCommand, object_id),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "left_to_right",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_BOOLEAN,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgs__msg__PickAndPlaceCommand, left_to_right),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "target_position",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_MESSAGE,  // type
    0,  // upper bound of string
    NULL,  // members of sub message (initialized later)
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(my_msgs__msg__PickAndPlaceCommand, target_position),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL,  // fetch(index, &value) function pointer
    NULL,  // assign(index, value) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_members = {
  "my_msgs__msg",  // message namespace
  "PickAndPlaceCommand",  // message name
  4,  // number of fields
  sizeof(my_msgs__msg__PickAndPlaceCommand),
  my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_member_array,  // message members
  my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_init_function,  // function to initialize message memory (memory has to be allocated)
  my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_type_support_handle = {
  0,
  &my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_members,
  get_message_typesupport_handle_function,
  &my_msgs__msg__PickAndPlaceCommand__get_type_hash,
  &my_msgs__msg__PickAndPlaceCommand__get_type_description,
  &my_msgs__msg__PickAndPlaceCommand__get_type_description_sources,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_my_msgs
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, my_msgs, msg, PickAndPlaceCommand)() {
  my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_member_array[3].members_ =
    ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, geometry_msgs, msg, Point)();
  if (!my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_type_support_handle.typesupport_identifier) {
    my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &my_msgs__msg__PickAndPlaceCommand__rosidl_typesupport_introspection_c__PickAndPlaceCommand_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif
