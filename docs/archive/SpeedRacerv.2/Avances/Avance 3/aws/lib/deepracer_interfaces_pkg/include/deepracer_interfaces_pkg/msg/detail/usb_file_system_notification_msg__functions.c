// generated from rosidl_generator_c/resource/idl__functions.c.em
// with input from deepracer_interfaces_pkg:msg/USBFileSystemNotificationMsg.idl
// generated code does not contain a copyright notice
#include "deepracer_interfaces_pkg/msg/detail/usb_file_system_notification_msg__functions.h"

#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>


// Include directives for member types
// Member `path`
// Member `file_name`
// Member `callback_name`
// Member `node_name`
#include "rosidl_runtime_c/string_functions.h"

bool
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__init(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg * msg)
{
  if (!msg) {
    return false;
  }
  // path
  if (!rosidl_runtime_c__String__init(&msg->path)) {
    deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(msg);
    return false;
  }
  // file_name
  if (!rosidl_runtime_c__String__init(&msg->file_name)) {
    deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(msg);
    return false;
  }
  // callback_name
  if (!rosidl_runtime_c__String__init(&msg->callback_name)) {
    deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(msg);
    return false;
  }
  // node_name
  if (!rosidl_runtime_c__String__init(&msg->node_name)) {
    deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(msg);
    return false;
  }
  return true;
}

void
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg * msg)
{
  if (!msg) {
    return;
  }
  // path
  rosidl_runtime_c__String__fini(&msg->path);
  // file_name
  rosidl_runtime_c__String__fini(&msg->file_name);
  // callback_name
  rosidl_runtime_c__String__fini(&msg->callback_name);
  // node_name
  rosidl_runtime_c__String__fini(&msg->node_name);
}

deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg *
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__create()
{
  deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg * msg = (deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg *)malloc(sizeof(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg));
  if (!msg) {
    return NULL;
  }
  memset(msg, 0, sizeof(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg));
  bool success = deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__init(msg);
  if (!success) {
    free(msg);
    return NULL;
  }
  return msg;
}

void
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__destroy(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg * msg)
{
  if (msg) {
    deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(msg);
  }
  free(msg);
}


bool
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence__init(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence * array, size_t size)
{
  if (!array) {
    return false;
  }
  deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg * data = NULL;
  if (size) {
    data = (deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg *)calloc(size, sizeof(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg));
    if (!data) {
      return false;
    }
    // initialize all array elements
    size_t i;
    for (i = 0; i < size; ++i) {
      bool success = deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__init(&data[i]);
      if (!success) {
        break;
      }
    }
    if (i < size) {
      // if initialization failed finalize the already initialized array elements
      for (; i > 0; --i) {
        deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(&data[i - 1]);
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
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence__fini(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence * array)
{
  if (!array) {
    return;
  }
  if (array->data) {
    // ensure that data and capacity values are consistent
    assert(array->capacity > 0);
    // finalize all array elements
    for (size_t i = 0; i < array->capacity; ++i) {
      deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__fini(&array->data[i]);
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

deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence *
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence__create(size_t size)
{
  deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence * array = (deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence *)malloc(sizeof(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence));
  if (!array) {
    return NULL;
  }
  bool success = deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence__init(array, size);
  if (!success) {
    free(array);
    return NULL;
  }
  return array;
}

void
deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence__destroy(deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence * array)
{
  if (array) {
    deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence__fini(array);
  }
  free(array);
}
