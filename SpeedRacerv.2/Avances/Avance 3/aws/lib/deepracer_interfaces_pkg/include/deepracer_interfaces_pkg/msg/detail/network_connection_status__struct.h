// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/NetworkConnectionStatus.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__NETWORK_CONNECTION_STATUS__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__NETWORK_CONNECTION_STATUS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/NetworkConnectionStatus in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__NetworkConnectionStatus
{
  bool network_connected;
} deepracer_interfaces_pkg__msg__NetworkConnectionStatus;

// Struct for a sequence of deepracer_interfaces_pkg__msg__NetworkConnectionStatus.
typedef struct deepracer_interfaces_pkg__msg__NetworkConnectionStatus__Sequence
{
  deepracer_interfaces_pkg__msg__NetworkConnectionStatus * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__NetworkConnectionStatus__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__NETWORK_CONNECTION_STATUS__STRUCT_H_
