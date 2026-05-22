// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/ModelOptimizeSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__STRUCT_H_

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

// Struct defined in srv/ModelOptimizeSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request
{
  rosidl_runtime_c__String model_name;
  rosidl_runtime_c__int32__Sequence model_metadata_sensors;
  int32_t training_algorithm;
  rosidl_runtime_c__String img_format;
  int32_t width;
  int32_t height;
  int32_t num_channels;
  int32_t lidar_channels;
  int32_t platform;
} deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request__Sequence;


// Constants defined in the message

// Include directives for member types
// Member 'artifact_path'
// already included above
// #include "rosidl_runtime_c/string.h"

// Struct defined in srv/ModelOptimizeSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response
{
  rosidl_runtime_c__String artifact_path;
  int32_t error;
} deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__STRUCT_H_
