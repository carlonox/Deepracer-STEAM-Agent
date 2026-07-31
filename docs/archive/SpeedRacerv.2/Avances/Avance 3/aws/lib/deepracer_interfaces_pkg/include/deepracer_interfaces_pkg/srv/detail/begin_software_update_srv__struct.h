// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/BeginSoftwareUpdateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/BeginSoftwareUpdateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request
{
  int32_t sleep_time_before_reboot;
} deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/BeginSoftwareUpdateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response
{
  bool response_status;
} deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__STRUCT_H_
