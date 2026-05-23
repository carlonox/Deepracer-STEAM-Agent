// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:msg/USBFileSystemNotificationMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Include directives for member types
// Member 'path'
// Member 'file_name'
// Member 'callback_name'
// Member 'node_name'
#include "rosidl_runtime_c/string.h"

// Struct defined in msg/USBFileSystemNotificationMsg in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg
{
  rosidl_runtime_c__String path;
  rosidl_runtime_c__String file_name;
  rosidl_runtime_c__String callback_name;
  rosidl_runtime_c__String node_name;
} deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg;

// Struct for a sequence of deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg.
typedef struct deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence
{
  deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__STRUCT_H_
