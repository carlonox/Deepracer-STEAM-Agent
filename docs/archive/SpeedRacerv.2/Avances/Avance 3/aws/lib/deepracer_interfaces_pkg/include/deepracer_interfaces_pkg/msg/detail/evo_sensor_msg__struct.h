// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/EvoSensorMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'images'
#include "sensor_msgs/msg/detail/image__struct.h"
// Member 'lidar_data'
#include "rosidl_runtime_c/primitives_sequence.h"

// Struct defined in msg/EvoSensorMsg in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__EvoSensorMsg
{
  sensor_msgs__msg__Image__Sequence images;
  rosidl_runtime_c__float__Sequence lidar_data;
} deepracer_interfaces_pkg__msg__EvoSensorMsg;

// Struct for a sequence of deepracer_interfaces_pkg__msg__EvoSensorMsg.
typedef struct deepracer_interfaces_pkg__msg__EvoSensorMsg__Sequence
{
  deepracer_interfaces_pkg__msg__EvoSensorMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__EvoSensorMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__STRUCT_H_
