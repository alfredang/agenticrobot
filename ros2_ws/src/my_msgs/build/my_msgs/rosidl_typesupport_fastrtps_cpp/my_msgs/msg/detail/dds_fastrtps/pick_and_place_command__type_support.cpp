// generated from rosidl_typesupport_fastrtps_cpp/resource/idl__type_support.cpp.em
// with input from my_msgs:msg/PickAndPlaceCommand.idl
// generated code does not contain a copyright notice
#include "my_msgs/msg/detail/pick_and_place_command__rosidl_typesupport_fastrtps_cpp.hpp"
#include "my_msgs/msg/detail/pick_and_place_command__functions.h"
#include "my_msgs/msg/detail/pick_and_place_command__struct.hpp"

#include <limits>
#include <stdexcept>
#include <string>
#include "rosidl_typesupport_cpp/message_type_support.hpp"
#include "rosidl_typesupport_fastrtps_cpp/identifier.hpp"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support.h"
#include "rosidl_typesupport_fastrtps_cpp/message_type_support_decl.hpp"
#include "rosidl_typesupport_fastrtps_cpp/wstring_conversion.hpp"
#include "fastcdr/Cdr.h"


// forward declaration of message dependencies and their conversion functions
namespace geometry_msgs
{
namespace msg
{
namespace typesupport_fastrtps_cpp
{
bool cdr_serialize(
  const geometry_msgs::msg::Point &,
  eprosima::fastcdr::Cdr &);
bool cdr_deserialize(
  eprosima::fastcdr::Cdr &,
  geometry_msgs::msg::Point &);
size_t get_serialized_size(
  const geometry_msgs::msg::Point &,
  size_t current_alignment);
size_t
max_serialized_size_Point(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment);
}  // namespace typesupport_fastrtps_cpp
}  // namespace msg
}  // namespace geometry_msgs


namespace my_msgs
{

namespace msg
{

namespace typesupport_fastrtps_cpp
{

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_msgs
cdr_serialize(
  const my_msgs::msg::PickAndPlaceCommand & ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  // Member: command_type
  cdr << ros_message.command_type;
  // Member: object_id
  cdr << ros_message.object_id;
  // Member: left_to_right
  cdr << (ros_message.left_to_right ? true : false);
  // Member: target_position
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_serialize(
    ros_message.target_position,
    cdr);
  return true;
}

bool
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_msgs
cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  my_msgs::msg::PickAndPlaceCommand & ros_message)
{
  // Member: command_type
  cdr >> ros_message.command_type;

  // Member: object_id
  cdr >> ros_message.object_id;

  // Member: left_to_right
  {
    uint8_t tmp;
    cdr >> tmp;
    ros_message.left_to_right = tmp ? true : false;
  }

  // Member: target_position
  geometry_msgs::msg::typesupport_fastrtps_cpp::cdr_deserialize(
    cdr, ros_message.target_position);

  return true;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_msgs
get_serialized_size(
  const my_msgs::msg::PickAndPlaceCommand & ros_message,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  (void)padding;
  (void)wchar_size;

  // Member: command_type
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.command_type.size() + 1);
  // Member: object_id
  current_alignment += padding +
    eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
    (ros_message.object_id.size() + 1);
  // Member: left_to_right
  {
    size_t item_size = sizeof(ros_message.left_to_right);
    current_alignment += item_size +
      eprosima::fastcdr::Cdr::alignment(current_alignment, item_size);
  }
  // Member: target_position

  current_alignment +=
    geometry_msgs::msg::typesupport_fastrtps_cpp::get_serialized_size(
    ros_message.target_position, current_alignment);

  return current_alignment - initial_alignment;
}

size_t
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_PUBLIC_my_msgs
max_serialized_size_PickAndPlaceCommand(
  bool & full_bounded,
  bool & is_plain,
  size_t current_alignment)
{
  size_t initial_alignment = current_alignment;

  const size_t padding = 4;
  const size_t wchar_size = 4;
  size_t last_member_size = 0;
  (void)last_member_size;
  (void)padding;
  (void)wchar_size;

  full_bounded = true;
  is_plain = true;


  // Member: command_type
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: object_id
  {
    size_t array_size = 1;

    full_bounded = false;
    is_plain = false;
    for (size_t index = 0; index < array_size; ++index) {
      current_alignment += padding +
        eprosima::fastcdr::Cdr::alignment(current_alignment, padding) +
        1;
    }
  }

  // Member: left_to_right
  {
    size_t array_size = 1;

    last_member_size = array_size * sizeof(uint8_t);
    current_alignment += array_size * sizeof(uint8_t);
  }

  // Member: target_position
  {
    size_t array_size = 1;


    last_member_size = 0;
    for (size_t index = 0; index < array_size; ++index) {
      bool inner_full_bounded;
      bool inner_is_plain;
      size_t inner_size =
        geometry_msgs::msg::typesupport_fastrtps_cpp::max_serialized_size_Point(
        inner_full_bounded, inner_is_plain, current_alignment);
      last_member_size += inner_size;
      current_alignment += inner_size;
      full_bounded &= inner_full_bounded;
      is_plain &= inner_is_plain;
    }
  }

  size_t ret_val = current_alignment - initial_alignment;
  if (is_plain) {
    // All members are plain, and type is not empty.
    // We still need to check that the in-memory alignment
    // is the same as the CDR mandated alignment.
    using DataType = my_msgs::msg::PickAndPlaceCommand;
    is_plain =
      (
      offsetof(DataType, target_position) +
      last_member_size
      ) == ret_val;
  }

  return ret_val;
}

static bool _PickAndPlaceCommand__cdr_serialize(
  const void * untyped_ros_message,
  eprosima::fastcdr::Cdr & cdr)
{
  auto typed_message =
    static_cast<const my_msgs::msg::PickAndPlaceCommand *>(
    untyped_ros_message);
  return cdr_serialize(*typed_message, cdr);
}

static bool _PickAndPlaceCommand__cdr_deserialize(
  eprosima::fastcdr::Cdr & cdr,
  void * untyped_ros_message)
{
  auto typed_message =
    static_cast<my_msgs::msg::PickAndPlaceCommand *>(
    untyped_ros_message);
  return cdr_deserialize(cdr, *typed_message);
}

static uint32_t _PickAndPlaceCommand__get_serialized_size(
  const void * untyped_ros_message)
{
  auto typed_message =
    static_cast<const my_msgs::msg::PickAndPlaceCommand *>(
    untyped_ros_message);
  return static_cast<uint32_t>(get_serialized_size(*typed_message, 0));
}

static size_t _PickAndPlaceCommand__max_serialized_size(char & bounds_info)
{
  bool full_bounded;
  bool is_plain;
  size_t ret_val;

  ret_val = max_serialized_size_PickAndPlaceCommand(full_bounded, is_plain, 0);

  bounds_info =
    is_plain ? ROSIDL_TYPESUPPORT_FASTRTPS_PLAIN_TYPE :
    full_bounded ? ROSIDL_TYPESUPPORT_FASTRTPS_BOUNDED_TYPE : ROSIDL_TYPESUPPORT_FASTRTPS_UNBOUNDED_TYPE;
  return ret_val;
}

static message_type_support_callbacks_t _PickAndPlaceCommand__callbacks = {
  "my_msgs::msg",
  "PickAndPlaceCommand",
  _PickAndPlaceCommand__cdr_serialize,
  _PickAndPlaceCommand__cdr_deserialize,
  _PickAndPlaceCommand__get_serialized_size,
  _PickAndPlaceCommand__max_serialized_size
};

static rosidl_message_type_support_t _PickAndPlaceCommand__handle = {
  rosidl_typesupport_fastrtps_cpp::typesupport_identifier,
  &_PickAndPlaceCommand__callbacks,
  get_message_typesupport_handle_function,
  &my_msgs__msg__PickAndPlaceCommand__get_type_hash,
  &my_msgs__msg__PickAndPlaceCommand__get_type_description,
  &my_msgs__msg__PickAndPlaceCommand__get_type_description_sources,
};

}  // namespace typesupport_fastrtps_cpp

}  // namespace msg

}  // namespace my_msgs

namespace rosidl_typesupport_fastrtps_cpp
{

template<>
ROSIDL_TYPESUPPORT_FASTRTPS_CPP_EXPORT_my_msgs
const rosidl_message_type_support_t *
get_message_type_support_handle<my_msgs::msg::PickAndPlaceCommand>()
{
  return &my_msgs::msg::typesupport_fastrtps_cpp::_PickAndPlaceCommand__handle;
}

}  // namespace rosidl_typesupport_fastrtps_cpp

#ifdef __cplusplus
extern "C"
{
#endif

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_fastrtps_cpp, my_msgs, msg, PickAndPlaceCommand)() {
  return &my_msgs::msg::typesupport_fastrtps_cpp::_PickAndPlaceCommand__handle;
}

#ifdef __cplusplus
}
#endif
