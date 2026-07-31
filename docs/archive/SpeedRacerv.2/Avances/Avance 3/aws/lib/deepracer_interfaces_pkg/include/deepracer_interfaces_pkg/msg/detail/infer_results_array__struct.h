// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/InferResultsArray.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'results'
#include "deepracer_interfaces_pkg/msg/detail/infer_results__struct.h"
// Member 'images'
#include "sensor_msgs/msg/detail/image__struct.h"

// Struct defined in msg/InferResultsArray in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__InferResultsArray
{
  deepracer_interfaces_pkg__msg__InferResults__Sequence results;
  sensor_msgs__msg__Image__Sequence images;
} deepracer_interfaces_pkg__msg__InferResultsArray;

// Struct for a sequence of deepracer_interfaces_pkg__msg__InferResultsArray.
typedef struct deepracer_interfaces_pkg__msg__InferResultsArray__Sequence
{
  deepracer_interfaces_pkg__msg__InferResultsArray * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__InferResultsArray__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__STRUCT_H_
