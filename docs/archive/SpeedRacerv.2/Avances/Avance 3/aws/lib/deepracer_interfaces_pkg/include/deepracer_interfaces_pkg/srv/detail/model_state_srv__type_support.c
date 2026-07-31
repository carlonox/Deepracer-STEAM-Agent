// generated from rosidl_typesupport_introspection_c/resource/idl__type_support.c.em
// with input from deepracer_interfaces_pkg:srv/ModelStateSrv.idl
// generated code does not contain a copyright notice

#include <stddef.h>
#include "deepracer_interfaces_pkg/srv/detail/model_state_srv__rosidl_typesupport_introspection_c.h"
#include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
#include "rosidl_typesupport_introspection_c/field_types.h"
#include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/message_introspection.h"
#include "deepracer_interfaces_pkg/srv/detail/model_state_srv__functions.h"
#include "deepracer_interfaces_pkg/srv/detail/model_state_srv__struct.h"


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

void ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  deepracer_interfaces_pkg__srv__ModelStateSrv_Request__init(message_memory);
}

void ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_fini_function(void * message_memory)
{
  deepracer_interfaces_pkg__srv__ModelStateSrv_Request__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_member_array[12] = {
  {
    "model_name",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_STRING,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, model_name),  // bytes offset in struct
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
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, model_metadata_sensors),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "training_algorithm",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, training_algorithm),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "action_space_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, action_space_type),  // bytes offset in struct
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
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, img_format),  // bytes offset in struct
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
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, width),  // bytes offset in struct
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
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, height),  // bytes offset in struct
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
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, num_channels),  // bytes offset in struct
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
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, lidar_channels),  // bytes offset in struct
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
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, platform),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "task_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, task_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  },
  {
    "pre_process_type",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT8,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request, pre_process_type),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_members = {
  "deepracer_interfaces_pkg__srv",  // message namespace
  "ModelStateSrv_Request",  // message name
  12,  // number of fields
  sizeof(deepracer_interfaces_pkg__srv__ModelStateSrv_Request),
  ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_member_array,  // message members
  ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_init_function,  // function to initialize message memory (memory has to be allocated)
  ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_type_support_handle = {
  0,
  &ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelStateSrv_Request)() {
  if (!ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_type_support_handle.typesupport_identifier) {
    ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ModelStateSrv_Request__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

// already included above
// #include <stddef.h>
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_state_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "rosidl_typesupport_introspection_c/field_types.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
// already included above
// #include "rosidl_typesupport_introspection_c/message_introspection.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_state_srv__functions.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_state_srv__struct.h"


#ifdef __cplusplus
extern "C"
{
#endif

void ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_init_function(
  void * message_memory, enum rosidl_runtime_c__message_initialization _init)
{
  // TODO(karsten1987): initializers are not yet implemented for typesupport c
  // see https://github.com/ros2/ros2/issues/397
  (void) _init;
  deepracer_interfaces_pkg__srv__ModelStateSrv_Response__init(message_memory);
}

void ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_fini_function(void * message_memory)
{
  deepracer_interfaces_pkg__srv__ModelStateSrv_Response__fini(message_memory);
}

static rosidl_typesupport_introspection_c__MessageMember ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_member_array[1] = {
  {
    "error",  // name
    rosidl_typesupport_introspection_c__ROS_TYPE_INT32,  // type
    0,  // upper bound of string
    NULL,  // members of sub message
    false,  // is array
    0,  // array size
    false,  // is upper bound
    offsetof(deepracer_interfaces_pkg__srv__ModelStateSrv_Response, error),  // bytes offset in struct
    NULL,  // default value
    NULL,  // size() function pointer
    NULL,  // get_const(index) function pointer
    NULL,  // get(index) function pointer
    NULL  // resize(index) function pointer
  }
};

static const rosidl_typesupport_introspection_c__MessageMembers ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_members = {
  "deepracer_interfaces_pkg__srv",  // message namespace
  "ModelStateSrv_Response",  // message name
  1,  // number of fields
  sizeof(deepracer_interfaces_pkg__srv__ModelStateSrv_Response),
  ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_member_array,  // message members
  ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_init_function,  // function to initialize message memory (memory has to be allocated)
  ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_fini_function  // function to terminate message instance (will not free memory)
};

// this is not const since it must be initialized on first access
// since C does not allow non-integral compile-time constants
static rosidl_message_type_support_t ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_type_support_handle = {
  0,
  &ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_members,
  get_message_typesupport_handle_function,
};

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelStateSrv_Response)() {
  if (!ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_type_support_handle.typesupport_identifier) {
    ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  return &ModelStateSrv_Response__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_type_support_handle;
}
#ifdef __cplusplus
}
#endif

#include "rosidl_runtime_c/service_type_support_struct.h"
// already included above
// #include "deepracer_interfaces_pkg/msg/rosidl_typesupport_introspection_c__visibility_control.h"
// already included above
// #include "deepracer_interfaces_pkg/srv/detail/model_state_srv__rosidl_typesupport_introspection_c.h"
// already included above
// #include "rosidl_typesupport_introspection_c/identifier.h"
#include "rosidl_typesupport_introspection_c/service_introspection.h"

// this is intentionally not const to allow initialization later to prevent an initialization race
static rosidl_typesupport_introspection_c__ServiceMembers deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_service_members = {
  "deepracer_interfaces_pkg__srv",  // service namespace
  "ModelStateSrv",  // service name
  // these two fields are initialized below on the first access
  NULL,  // request message
  // deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_Request_message_type_support_handle,
  NULL  // response message
  // deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_Response_message_type_support_handle
};

static rosidl_service_type_support_t deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_service_type_support_handle = {
  0,
  &deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_service_members,
  get_service_typesupport_handle_function,
};

// Forward declaration of request/response type support functions
const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelStateSrv_Request)();

const rosidl_message_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelStateSrv_Response)();

ROSIDL_TYPESUPPORT_INTROSPECTION_C_EXPORT_deepracer_interfaces_pkg
const rosidl_service_type_support_t *
ROSIDL_TYPESUPPORT_INTERFACE__SERVICE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelStateSrv)() {
  if (!deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_service_type_support_handle.typesupport_identifier) {
    deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_service_type_support_handle.typesupport_identifier =
      rosidl_typesupport_introspection_c__identifier;
  }
  rosidl_typesupport_introspection_c__ServiceMembers * service_members =
    (rosidl_typesupport_introspection_c__ServiceMembers *)deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_service_type_support_handle.data;

  if (!service_members->request_members_) {
    service_members->request_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelStateSrv_Request)()->data;
  }
  if (!service_members->response_members_) {
    service_members->response_members_ =
      (const rosidl_typesupport_introspection_c__MessageMembers *)
      ROSIDL_TYPESUPPORT_INTERFACE__MESSAGE_SYMBOL_NAME(rosidl_typesupport_introspection_c, deepracer_interfaces_pkg, srv, ModelStateSrv_Response)()->data;
  }

  return &deepracer_interfaces_pkg__srv__detail__model_state_srv__rosidl_typesupport_introspection_c__ModelStateSrv_service_type_support_handle;
}
