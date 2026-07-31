// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/InferResults.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in msg/InferResults in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__InferResults
{
  int32_t class_label;
  float class_prob;
  float x_min;
  float y_min;
  float x_max;
  float y_max;
} deepracer_interfaces_pkg__msg__InferResults;

// Struct for a sequence of deepracer_interfaces_pkg__msg__InferResults.
typedef struct deepracer_interfaces_pkg__msg__InferResults__Sequence
{
  deepracer_interfaces_pkg__msg__InferResults * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__InferResults__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__STRUCT_H_
