// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/USBMountPointManagerSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_MOUNT_POINT_MANAGER_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_MOUNT_POINT_MANAGER_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/usb_mount_point_manager_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_USBMountPointManagerSrv_Request_action
{
public:
  explicit Init_USBMountPointManagerSrv_Request_action(::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request action(::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request::_action_type arg)
  {
    msg_.action = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request msg_;
};

class Init_USBMountPointManagerSrv_Request_node_name
{
public:
  Init_USBMountPointManagerSrv_Request_node_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_USBMountPointManagerSrv_Request_action node_name(::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return Init_USBMountPointManagerSrv_Request_action(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_USBMountPointManagerSrv_Request_node_name();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_USBMountPointManagerSrv_Response_error
{
public:
  Init_USBMountPointManagerSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response error(::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::USBMountPointManagerSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_USBMountPointManagerSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_MOUNT_POINT_MANAGER_SRV__BUILDER_HPP_
