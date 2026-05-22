// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/CameraMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__CAMERA_MSG__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__CAMERA_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'images'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in msg/CameraMsg in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__CameraMsg
{
  sensor_msgs__msg__Image__Sequence images;
} deepracer_interfaces_pkg__msg__CameraMsg;

// Struct for a sequence of deepracer_interfaces_pkg__msg__CameraMsg.
typedef struct deepracer_interfaces_pkg__msg__CameraMsg__Sequence
{
  deepracer_interfaces_pkg__msg__CameraMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__CameraMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__CAMERA_MSG__STRUCT_H_
