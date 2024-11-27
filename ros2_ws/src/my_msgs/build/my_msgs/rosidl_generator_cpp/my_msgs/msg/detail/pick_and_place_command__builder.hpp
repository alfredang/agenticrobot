// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from my_msgs:msg/PickAndPlaceCommand.idl
// generated code does not contain a copyright notice

#ifndef MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__BUILDER_HPP_
#define MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__BUILDER_HPP_

#include <algorithm>
#include <utility>

#include "my_msgs/msg/detail/pick_and_place_command__struct.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


namespace my_msgs
{

namespace msg
{

namespace builder
{

class Init_PickAndPlaceCommand_target_position
{
public:
  explicit Init_PickAndPlaceCommand_target_position(::my_msgs::msg::PickAndPlaceCommand & msg)
  : msg_(msg)
  {}
  ::my_msgs::msg::PickAndPlaceCommand target_position(::my_msgs::msg::PickAndPlaceCommand::_target_position_type arg)
  {
    msg_.target_position = std::move(arg);
    return std::move(msg_);
  }

private:
  ::my_msgs::msg::PickAndPlaceCommand msg_;
};

class Init_PickAndPlaceCommand_left_to_right
{
public:
  explicit Init_PickAndPlaceCommand_left_to_right(::my_msgs::msg::PickAndPlaceCommand & msg)
  : msg_(msg)
  {}
  Init_PickAndPlaceCommand_target_position left_to_right(::my_msgs::msg::PickAndPlaceCommand::_left_to_right_type arg)
  {
    msg_.left_to_right = std::move(arg);
    return Init_PickAndPlaceCommand_target_position(msg_);
  }

private:
  ::my_msgs::msg::PickAndPlaceCommand msg_;
};

class Init_PickAndPlaceCommand_object_id
{
public:
  explicit Init_PickAndPlaceCommand_object_id(::my_msgs::msg::PickAndPlaceCommand & msg)
  : msg_(msg)
  {}
  Init_PickAndPlaceCommand_left_to_right object_id(::my_msgs::msg::PickAndPlaceCommand::_object_id_type arg)
  {
    msg_.object_id = std::move(arg);
    return Init_PickAndPlaceCommand_left_to_right(msg_);
  }

private:
  ::my_msgs::msg::PickAndPlaceCommand msg_;
};

class Init_PickAndPlaceCommand_command_type
{
public:
  Init_PickAndPlaceCommand_command_type()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_PickAndPlaceCommand_object_id command_type(::my_msgs::msg::PickAndPlaceCommand::_command_type_type arg)
  {
    msg_.command_type = std::move(arg);
    return Init_PickAndPlaceCommand_object_id(msg_);
  }

private:
  ::my_msgs::msg::PickAndPlaceCommand msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::my_msgs::msg::PickAndPlaceCommand>()
{
  return my_msgs::msg::builder::Init_PickAndPlaceCommand_command_type();
}

}  // namespace my_msgs

#endif  // MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__BUILDER_HPP_
