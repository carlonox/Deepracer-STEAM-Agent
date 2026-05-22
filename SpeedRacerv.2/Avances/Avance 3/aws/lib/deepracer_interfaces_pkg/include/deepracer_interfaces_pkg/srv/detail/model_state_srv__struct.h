// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/ModelStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_STATE_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_STATE_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'model_name'
// Member 'img_format'
#include "rosidl_runtime_c/string.h"
// Member 'model_metadata_sensors'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in srv/ModelStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__ModelStateSrv_Request
{
  rosidl_runtime_c__String model_name;
  rosidl_runtime_c__int32__Sequence model_metadata_sensors;
  int8_t training_algorithm;
  int8_t action_space_type;
  rosidl_runtime_c__String img_format;
  int32_t width;
  int32_t height;
  int32_t num_channels;
  int32_t lidar_channels;
  int32_t platform;
  int8_t task_type;
  int8_t pre_process_type;
} deepracer_interfaces_pkg__srv__ModelStateSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__ModelStateSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__ModelStateSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__ModelStateSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__ModelStateSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/ModelStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__ModelStateSrv_Response
{
  int32_t error;
} deepracer_interfaces_pkg__srv__ModelStateSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__ModelStateSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__ModelStateSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__ModelStateSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__ModelStateSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_STATE_SRV__STRUCT_H_
