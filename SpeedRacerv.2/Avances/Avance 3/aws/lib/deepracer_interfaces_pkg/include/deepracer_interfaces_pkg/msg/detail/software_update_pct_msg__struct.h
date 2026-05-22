// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/SoftwareUpdatePctMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'status'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/SoftwareUpdatePctMsg in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg
{
  float update_pct;
  rosidl_runtime_c__String status;
} deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg;

// Struct for a sequence of deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg.
typedef struct deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg__Sequence
{
  deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__STRUCT_H_
