// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from deepracer_interfaces_pkg:srv/ModelOptimizeSrv.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__rosidl_typesupport_introspection_c.h"
#include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__functions.h"
#include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__struct.h"


// Include directives for member types
// Member `model_name`
// Member `img_format`
#include "rosidl_runtime_c/string_functions.h"
// Member `model_metadata_sensors`
#include "rosidl_runtime_c/primitives_sequence_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request__init(message_memory);
}

void ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_fini_function(void * message_memory)
{
  deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_member_array[9] = {
  {
    "model_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, model_name),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "model_metadata_sensors",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    true,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, model_metadata_sensors),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "training_algorithm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, training_algorithm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "img_format",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, img_format),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "width",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, width),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "height",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, height),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "num_channels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, num_channels),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "lidar_channels",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, lidar_channels),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "platform",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request, platform),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_members = {
  "deepracer_interfaces_pkg__srv",  // message namespace
  "ModelOptimizeSrv_Request",  // message name
  9,  // number of fields
  sizeof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request),
  ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_member_array,  // message members
  ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_type_support_handle = {
  0,
  &ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelOptimizeSrv_Request)() {
  if (!ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_type_support_handle.typesupport_identifier) {
    ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ModelOptimizeSrv_Request__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__functions.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__struct.h"


// Include directives for member types
// Member `artifact_path`
// already included above
// #include "rosidl_runtime_c/string_functions.h"

#ifdef __cplusplus
extern "C"
{
#endif

void ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response__init(message_memory);
}

void ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_fini_function(void * message_memory)
{
  deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_member_array[2] = {
  {
    "artifact_path",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response, artifact_path),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_members = {
  "deepracer_interfaces_pkg__srv",  // message namespace
  "ModelOptimizeSrv_Response",  // message name
  2,  // number of fields
  sizeof(deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response),
  ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_member_array,  // message members
  ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_type_support_handle = {
  0,
  &ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelOptimizeSrv_Response)() {
  if (!ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_type_support_handle.typesupport_identifier) {
    ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ModelOptimizeSrv_Response__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_optimize_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_service_members = {
  "deepracer_interfaces_pkg__srv",  // service namespace
  "ModelOptimizeSrv",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Request_message_type_support_handle,
  NULL  // response message
  // deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_Response_message_type_support_handle
};

static rosidl_service_type_support_t deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_service_type_support_handle = {
  0,
  &deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelOptimizeSrv_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelOptimizeSrv_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelOptimizeSrv)() {
  if (!deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_service_type_support_handle.typesupport_identifier) {
    deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelOptimizeSrv_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelOptimizeSrv_Response)()->data;
  }

  return &deepracer_interfaces_pkg__srv__detail__model_optimize_srv__rosidl_typesupport_introspection_c__ModelOptimizeSrv_service_type_support_handle;
}
