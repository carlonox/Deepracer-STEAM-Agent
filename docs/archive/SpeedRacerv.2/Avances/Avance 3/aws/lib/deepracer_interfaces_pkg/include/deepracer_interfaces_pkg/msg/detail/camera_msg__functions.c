// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from deepracer_interfaces_pkg:msg/CameraMsg.idl
// generated code does not contain a copyright notice
#include "deepracer_interfaces_pkg/msg/detail/camera_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `images`
#include "sensor_msgs/msg/detail/image__functions.h"

bool
deepracer_interfaces_pkg__msg__CameraMsg__init(deepracer_interfaces_pkg__msg__CameraMsg * msg)
{
  if (!msg) {
    return false;
  }
  // images
  if (!sensor_msgs__msg__Image__Sequence__init(&msg->images, 0)) {
    deepracer_interfaces_pkg__msg__CameraMsg__fini(msg);
    return false;
  }
  return true;
}

void
deepracer_interfaces_pkg__msg__CameraMsg__fini(deepracer_interfaces_pkg__msg__CameraMsg * msg)
{
  if (!msg) {
    return;
  }
  // images
  sensor_msgs__msg__Image__Sequence__fini(&msg->images);
}

deepracer_interfaces_pkg__msg__CameraMsg *
deepracer_interfaces_pkg__msg__CameraMsg__create()
{
  deepracer_interfaces_pkg__msg__CameraMsg * msg = (deepracer_interfaces_pkg__msg__CameraMsg *)malloc(sizeof(deepracer_interfaces_pkg__msg__CameraMsg));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(deepracer_interfaces_pkg__msg__CameraMsg));
  bool success = deepracer_interfaces_pkg__msg__CameraMsg__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
deepracer_interfaces_pkg__msg__CameraMsg__destroy(deepracer_interfaces_pkg__msg__CameraMsg * msg)
{
  if (msg) {
    deepracer_interfaces_pkg__msg__CameraMsg__fini(msg);
  }
  free(msg);
}


bool
deepracer_interfaces_pkg__msg__CameraMsg__Sequence__init(deepracer_interfaces_pkg__msg__CameraMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  deepracer_interfaces_pkg__msg__CameraMsg * data = NULL;
  if (size) {
    data = (deepracer_interfaces_pkg__msg__CameraMsg *)calloc(size, sizeof(deepracer_interfaces_pkg__msg__CameraMsg));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = deepracer_interfaces_pkg__msg__CameraMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        deepracer_interfaces_pkg__msg__CameraMsg__fini(&data[i - 1]);
      }
      free(data);
      return false;
    }
  }
  array->data = data;
  array->size = size;
  array->capacity = size;
  return true;
}

void
deepracer_interfaces_pkg__msg__CameraMsg__Sequence__fini(deepracer_interfaces_pkg__msg__CameraMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      deepracer_interfaces_pkg__msg__CameraMsg__fini(&array->data[i]);
    }
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
  } else {
    // ensure that data, size, and capacity values are consistent
    assert(0 == array->size);
    assert(0 == array->capacity);
  }
}

deepracer_interfaces_pkg__msg__CameraMsg__Sequence *
deepracer_interfaces_pkg__msg__CameraMsg__Sequence__create(size_t size)
{
  deepracer_interfaces_pkg__msg__CameraMsg__Sequence * array = (deepracer_interfaces_pkg__msg__CameraMsg__Sequence *)malloc(sizeof(deepracer_interfaces_pkg__msg__CameraMsg__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = deepracer_interfaces_pkg__msg__CameraMsg__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
deepracer_interfaces_pkg__msg__CameraMsg__Sequence__destroy(deepracer_interfaces_pkg__msg__CameraMsg__Sequence * array)
{
  if (array) {
    deepracer_interfaces_pkg__msg__CameraMsg__Sequence__fini(array);
  }
  free(array);
}
