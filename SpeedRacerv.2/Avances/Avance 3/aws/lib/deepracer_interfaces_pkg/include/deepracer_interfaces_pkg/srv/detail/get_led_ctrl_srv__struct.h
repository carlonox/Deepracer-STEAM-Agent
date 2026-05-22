// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/GetLedCtrlSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetLedCtrlSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request
{
  uint8_t structure_needs_at_least_one_member;
} deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/GetLedCtrlSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response
{
  int32_t red;
  int32_t green;
  int32_t blue;
} deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__STRUCT_H_
