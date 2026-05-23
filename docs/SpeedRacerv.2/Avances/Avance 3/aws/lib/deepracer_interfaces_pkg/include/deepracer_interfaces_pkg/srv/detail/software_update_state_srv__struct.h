// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/SoftwareUpdateStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_STATE_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_STATE_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/SoftwareUpdateStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Request
{
  bool request;
} deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SoftwareUpdateStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Response
{
  int32_t update_state;
} deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__SoftwareUpdateStateSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_STATE_SRV__STRUCT_H_
