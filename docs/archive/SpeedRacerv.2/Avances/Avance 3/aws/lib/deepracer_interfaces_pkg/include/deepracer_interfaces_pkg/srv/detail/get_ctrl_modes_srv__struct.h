// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/GetCtrlModesSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CTRL_MODES_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CTRL_MODES_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetCtrlModesSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Request
{
  uint8_t structure_needs_at_least_one_member;
} deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'modes'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/GetCtrlModesSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Response
{
  rosidl_runtime_c__int32__Sequence modes;
  int32_t error;
} deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__GetCtrlModesSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CTRL_MODES_SRV__STRUCT_H_
