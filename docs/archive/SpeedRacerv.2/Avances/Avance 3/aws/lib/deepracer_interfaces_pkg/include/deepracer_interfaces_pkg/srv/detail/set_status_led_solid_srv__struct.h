// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/SetStatusLedSolidSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'color'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/SetStatusLedSolidSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Request
{
  int32_t led_index;
  rosidl_runtime_c__String color;
  float hold;
} deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SetStatusLedSolidSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Response
{
  int32_t error;
} deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__SetStatusLedSolidSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SET_STATUS_LED_SOLID_SRV__STRUCT_H_
