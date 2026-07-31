// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/ServoCtrlMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/ServoCtrlMsg in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__ServoCtrlMsg
{
  float angle;
  float throttle;
} deepracer_interfaces_pkg__msg__ServoCtrlMsg;

// Struct for a sequence of deepracer_interfaces_pkg__msg__ServoCtrlMsg.
typedef struct deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence
{
  deepracer_interfaces_pkg__msg__ServoCtrlMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__ServoCtrlMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__STRUCT_H_
