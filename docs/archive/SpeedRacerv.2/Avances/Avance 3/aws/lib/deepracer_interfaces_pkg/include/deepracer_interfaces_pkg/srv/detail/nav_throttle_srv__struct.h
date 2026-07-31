// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/NavThrottleSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__NAV_THROTTLE_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__NAV_THROTTLE_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/NavThrottleSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__NavThrottleSrv_Request
{
  float throttle;
} deepracer_interfaces_pkg__srv__NavThrottleSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__NavThrottleSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__NavThrottleSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__NavThrottleSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__NavThrottleSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/NavThrottleSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__NavThrottleSrv_Response
{
  int32_t error;
} deepracer_interfaces_pkg__srv__NavThrottleSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__NavThrottleSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__NavThrottleSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__NavThrottleSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__NavThrottleSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__NAV_THROTTLE_SRV__STRUCT_H_
