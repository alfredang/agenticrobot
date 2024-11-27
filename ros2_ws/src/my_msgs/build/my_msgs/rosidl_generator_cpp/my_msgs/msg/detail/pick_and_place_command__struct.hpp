// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from my_msgs:msg/PickAndPlaceCommand.idl
// generated code does not contain a copyright notice

#ifndef MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__STRUCT_HPP_
#define MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__STRUCT_HPP_

#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>

#include "rosidl_runtime_cpp/bounded_vector.hpp"
#include "rosidl_runtime_cpp/message_initialization.hpp"


// Include directives for member types
// Member 'target_position'
#include "geometry_msgs/msg/detail/point__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__my_msgs__msg__PickAndPlaceCommand __attribute__((deprecated))
#else
# define DEPRECATED__my_msgs__msg__PickAndPlaceCommand __declspec(deprecated)
#endif

namespace my_msgs
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct PickAndPlaceCommand_
{
  using Type = PickAndPlaceCommand_<ContainerAllocator>;

  explicit PickAndPlaceCommand_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : target_position(_init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_type = "";
      this->object_id = "";
      this->left_to_right = false;
    }
  }

  explicit PickAndPlaceCommand_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : command_type(_alloc),
    object_id(_alloc),
    target_position(_alloc, _init)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->command_type = "";
      this->object_id = "";
      this->left_to_right = false;
    }
  }

  // field types and members
  using _command_type_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _command_type_type command_type;
  using _object_id_type =
    std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>;
  _object_id_type object_id;
  using _left_to_right_type =
    bool;
  _left_to_right_type left_to_right;
  using _target_position_type =
    geometry_msgs::msg::Point_<ContainerAllocator>;
  _target_position_type target_position;

  // setters for named parameter idiom
  Type & set__command_type(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->command_type = _arg;
    return *this;
  }
  Type & set__object_id(
    const std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> & _arg)
  {
    this->object_id = _arg;
    return *this;
  }
  Type & set__left_to_right(
    const bool & _arg)
  {
    this->left_to_right = _arg;
    return *this;
  }
  Type & set__target_position(
    const geometry_msgs::msg::Point_<ContainerAllocator> & _arg)
  {
    this->target_position = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator> *;
  using ConstRawPtr =
    const my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__my_msgs__msg__PickAndPlaceCommand
    std::shared_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__my_msgs__msg__PickAndPlaceCommand
    std::shared_ptr<my_msgs::msg::PickAndPlaceCommand_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const PickAndPlaceCommand_ & other) const
  {
    if (this->command_type != other.command_type) {
      return false;
    }
    if (this->object_id != other.object_id) {
      return false;
    }
    if (this->left_to_right != other.left_to_right) {
      return false;
    }
    if (this->target_position != other.target_position) {
      return false;
    }
    return true;
  }
  bool operator!=(const PickAndPlaceCommand_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct PickAndPlaceCommand_

// alias to use template instance with default allocator
using PickAndPlaceCommand =
  my_msgs::msg::PickAndPlaceCommand_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace my_msgs

#endif  // MY_MSGS__MSG__DETAIL__PICK_AND_PLACE_COMMAND__STRUCT_HPP_
