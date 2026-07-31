// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/ActiveStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ACTIVE_STATE_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ACTIVE_STATE_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/ActiveStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__ActiveStateSrv_Request
{
  int8_t state;
} deepracer_interfaces_pkg__srv__ActiveStateSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__ActiveStateSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__ActiveStateSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ActiveStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__ActiveStateSrv_Response
{
  int32_t error;
} deepracer_interfaces_pkg__srv__ActiveStateSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__ActiveStateSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__ActiveStateSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__ActiveStateSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__ACTIVE_STATE_SRV__STRUCT_H_
