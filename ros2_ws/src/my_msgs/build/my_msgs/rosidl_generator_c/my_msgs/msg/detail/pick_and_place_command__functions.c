// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from my_msgs:msg/PickAndPlaceCommand.idl
// generated code does not contain a copyright notice
#include "my_msgs/msg/detail/pick_and_place_command__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

#include "rcutils/allocator.h"


// Include directives for member types
// Member `command_type`
// Member `object_id`
#include "rosidl_runtime_c/string_functions.h"
// Member `target_position`
#include "geometry_msgs/msg/detail/point__functions.h"

bool
my_msgs__msg__PickAndPlaceCommand__init(my_msgs__msg__PickAndPlaceCommand * msg)
{
  if (!msg) {
    return false;
  }
  // command_type
  if (!rosidl_runtime_c__String__init(&msg->command_type)) {
    my_msgs__msg__PickAndPlaceCommand__fini(msg);
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__init(&msg->object_id)) {
    my_msgs__msg__PickAndPlaceCommand__fini(msg);
    return false;
  }
  // left_to_right
  // target_position
  if (!geometry_msgs__msg__Point__init(&msg->target_position)) {
    my_msgs__msg__PickAndPlaceCommand__fini(msg);
    return false;
  }
  return true;
}

void
my_msgs__msg__PickAndPlaceCommand__fini(my_msgs__msg__PickAndPlaceCommand * msg)
{
  if (!msg) {
    return;
  }
  // command_type
  rosidl_runtime_c__String__fini(&msg->command_type);
  // object_id
  rosidl_runtime_c__String__fini(&msg->object_id);
  // left_to_right
  // target_position
  geometry_msgs__msg__Point__fini(&msg->target_position);
}

bool
my_msgs__msg__PickAndPlaceCommand__are_equal(const my_msgs__msg__PickAndPlaceCommand * lhs, const my_msgs__msg__PickAndPlaceCommand * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  // command_type
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->command_type), &(rhs->command_type)))
  {
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__are_equal(
      &(lhs->object_id), &(rhs->object_id)))
  {
    return false;
  }
  // left_to_right
  if (lhs->left_to_right != rhs->left_to_right) {
    return false;
  }
  // target_position
  if (!geometry_msgs__msg__Point__are_equal(
      &(lhs->target_position), &(rhs->target_position)))
  {
    return false;
  }
  return true;
}

bool
my_msgs__msg__PickAndPlaceCommand__copy(
  const my_msgs__msg__PickAndPlaceCommand * input,
  my_msgs__msg__PickAndPlaceCommand * output)
{
  if (!input || !output) {
    return false;
  }
  // command_type
  if (!rosidl_runtime_c__String__copy(
      &(input->command_type), &(output->command_type)))
  {
    return false;
  }
  // object_id
  if (!rosidl_runtime_c__String__copy(
      &(input->object_id), &(output->object_id)))
  {
    return false;
  }
  // left_to_right
  output->left_to_right = input->left_to_right;
  // target_position
  if (!geometry_msgs__msg__Point__copy(
      &(input->target_position), &(output->target_position)))
  {
    return false;
  }
  return true;
}

my_msgs__msg__PickAndPlaceCommand *
my_msgs__msg__PickAndPlaceCommand__create()
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msgs__msg__PickAndPlaceCommand * msg = (my_msgs__msg__PickAndPlaceCommand *)allocator.allocate(sizeof(my_msgs__msg__PickAndPlaceCommand), allocator.state);
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(my_msgs__msg__PickAndPlaceCommand));
  bool success = my_msgs__msg__PickAndPlaceCommand__init(msg);
  if (!success) {
    allocator.deallocate(msg, allocator.state);
    return NULL;
  }
  return msg;
}

void
my_msgs__msg__PickAndPlaceCommand__destroy(my_msgs__msg__PickAndPlaceCommand * msg)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (msg) {
    my_msgs__msg__PickAndPlaceCommand__fini(msg);
  }
  allocator.deallocate(msg, allocator.state);
}


bool
my_msgs__msg__PickAndPlaceCommand__Sequence__init(my_msgs__msg__PickAndPlaceCommand__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msgs__msg__PickAndPlaceCommand * data = NULL;

  if (size) {
    data = (my_msgs__msg__PickAndPlaceCommand *)allocator.zero_allocate(size, sizeof(my_msgs__msg__PickAndPlaceCommand), allocator.state);
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = my_msgs__msg__PickAndPlaceCommand__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        my_msgs__msg__PickAndPlaceCommand__fini(&data[i - 1]);
      }
      allocator.deallocate(data, allocator.state);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
my_msgs__msg__PickAndPlaceCommand__Sequence__fini(my_msgs__msg__PickAndPlaceCommand__Sequence * array)
{
  if (!array) {
    return;
  }
  rcutils_allocator_t allocator = rcutils_get_default_allocator();

  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      my_msgs__msg__PickAndPlaceCommand__fini(&array->data[i]);
    }
    allocator.deallocate(array->data, allocator.state);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

my_msgs__msg__PickAndPlaceCommand__Sequence *
my_msgs__msg__PickAndPlaceCommand__Sequence__create(size_t size)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  my_msgs__msg__PickAndPlaceCommand__Sequence * array = (my_msgs__msg__PickAndPlaceCommand__Sequence *)allocator.allocate(sizeof(my_msgs__msg__PickAndPlaceCommand__Sequence), allocator.state);
  if (!array) {
    return NULL;
  }
  bool success = my_msgs__msg__PickAndPlaceCommand__Sequence__init(array, size);
  if (!success) {
    allocator.deallocate(array, allocator.state);
    return NULL;
  }
  return array;
}

void
my_msgs__msg__PickAndPlaceCommand__Sequence__destroy(my_msgs__msg__PickAndPlaceCommand__Sequence * array)
{
  rcutils_allocator_t allocator = rcutils_get_default_allocator();
  if (array) {
    my_msgs__msg__PickAndPlaceCommand__Sequence__fini(array);
  }
  allocator.deallocate(array, allocator.state);
}

bool
my_msgs__msg__PickAndPlaceCommand__Sequence__are_equal(const my_msgs__msg__PickAndPlaceCommand__Sequence * lhs, const my_msgs__msg__PickAndPlaceCommand__Sequence * rhs)
{
  if (!lhs || !rhs) {
    return false;
  }
  if (lhs->size != rhs->size) {
    return false;
  }
  for (size_t i = 0; i < lhs->size; ++i) {
    if (!my_msgs__msg__PickAndPlaceCommand__are_equal(&(lhs->data[i]), &(rhs->data[i]))) {
      return false;
    }
  }
  return true;
}

bool
my_msgs__msg__PickAndPlaceCommand__Sequence__copy(
  const my_msgs__msg__PickAndPlaceCommand__Sequence * input,
  my_msgs__msg__PickAndPlaceCommand__Sequence * output)
{
  if (!input || !output) {
    return false;
  }
  if (output->capacity < input->size) {
    const size_t allocation_size =
      input->size * sizeof(my_msgs__msg__PickAndPlaceCommand);
    rcutils_allocator_t allocator = rcutils_get_default_allocator();
    my_msgs__msg__PickAndPlaceCommand * data =
      (my_msgs__msg__PickAndPlaceCommand *)allocator.reallocate(
      output->data, allocation_size, allocator.state);
    if (!data) {
      return false;
    }
    // If reallocation succeeded, memory may or may not have been moved
    // to fulfill the allocation request, invalidating output->data.
    output->data = data;
    for (size_t i = output->capacity; i < input->size; ++i) {
      if (!my_msgs__msg__PickAndPlaceCommand__init(&output->data[i])) {
        // If initialization of any new item fails, roll back
        // all previously initialized items. Existing items
        // in output are to be left unmodified.
        for (; i-- > output->capacity; ) {
          my_msgs__msg__PickAndPlaceCommand__fini(&output->data[i]);
        }
        return false;
      }
    }
    output->capacity = input->size;
  }
  output->size = input->size;
  for (size_t i = 0; i < input->size; ++i) {
    if (!my_msgs__msg__PickAndPlaceCommand__copy(
        &(input->data[i]), &(output->data[i])))
    {
      return false;
    }
  }
  return true;
}
