// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/GetCalibrationSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/GetCalibrationSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request
{
  int32_t cal_type;
} deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/GetCalibrationSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response
{
  int32_t max;
  int32_t mid;
  int32_t min;
  int32_t polarity;
  int32_t error;
} deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__STRUCT_H_
