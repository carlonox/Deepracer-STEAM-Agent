// generated from rosidl_generator_c/resource/idl__struct.h.em
// with input from deepracer_interfaces_pkg:srv/OTGLinkStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__OTG_LINK_STATE_SRV__STRUCT_H_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__OTG_LINK_STATE_SRV__STRUCT_H_

#ifdef __cplusplus
extern "C"
{
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>


// Constants defined in the message

// Struct defined in srv/OTGLinkStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Request
{
  uint8_t structure_needs_at_least_one_member;
} deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Request;

// Struct for a sequence of deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Request.
typedef struct deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Request__Sequence
{
  deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Request * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Request__Sequence;


// Constants defined in the message

// Struct defined in srv/OTGLinkStateSrv in the package deepracer_interfaces_pkg.
typedef struct deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Response
{
  bool link_state;
} deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Response;

// Struct for a sequence of deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Response.
typedef struct deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Response__Sequence
{
  deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Response * data;
  /// The number of valid items in data
  size_t size;
  /// The number of allocated items in data
  size_t capacity;
} deepracer_interfaces_pkg__srv__OTGLinkStateSrv_Response__Sequence;

#ifdef __cplusplus
}
#endif

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__OTG_LINK_STATE_SRV__STRUCT_H_
