// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/LoadModelSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LOAD_MODEL_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LOAD_MODEL_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'artifact_path'
#include "rosidl_runtime_c/string.h"

// Struct defined in srv/LoadModelSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__LoadModelSrv_Request
{
  rosidl_runtime_c__String artifact_path;
  int8_t task_type;
  int8_t pre_process_type;
  int8_t action_space_type;
} deepracer_interfaces_pkg__srv__LoadModelSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__LoadModelSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__LoadModelSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__LoadModelSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__LoadModelSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/LoadModelSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__LoadModelSrv_Response
{
  int32_t error;
} deepracer_interfaces_pkg__srv__LoadModelSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__LoadModelSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__LoadModelSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__LoadModelSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__LoadModelSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LOAD_MODEL_SRV__STRUCT_H_
