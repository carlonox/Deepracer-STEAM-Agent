// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/SoftwareUpdateCheckSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/SoftwareUpdateCheckSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request
{
  int32_t force_update_check;
} deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/SoftwareUpdateCheckSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response
{
  int32_t software_update_state;
} deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__STRUCT_H_
