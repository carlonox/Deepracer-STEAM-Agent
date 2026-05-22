// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/USBFileSystemSubscribeSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/usb_file_system_subscribe_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_USBFileSystemSubscribeSrv_Request_verify_name_exists
{
public:
  explicit Init_USBFileSystemSubscribeSrv_Request_verify_name_exists(::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request verify_name_exists(::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request::_verify_name_exists_type arg)
  {
    msg_.verify_name_exists = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request msg_;
};

class Init_USBFileSystemSubscribeSrv_Request_callback_name
{
public:
  explicit Init_USBFileSystemSubscribeSrv_Request_callback_name(::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request & msg)
  : msg_(msg)
  {}
  Init_USBFileSystemSubscribeSrv_Request_verify_name_exists callback_name(::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request::_callback_name_type arg)
  {
    msg_.callback_name = std::move(arg);
    return Init_USBFileSystemSubscribeSrv_Request_verify_name_exists(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request msg_;
};

class Init_USBFileSystemSubscribeSrv_Request_file_name
{
public:
  Init_USBFileSystemSubscribeSrv_Request_file_name()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_USBFileSystemSubscribeSrv_Request_callback_name file_name(::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request::_file_name_type arg)
  {
    msg_.file_name = std::move(arg);
    return Init_USBFileSystemSubscribeSrv_Request_callback_name(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_USBFileSystemSubscribeSrv_Request_file_name();
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_USBFileSystemSubscribeSrv_Response_error
{
public:
  Init_USBFileSystemSubscribeSrv_Response_error()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response error(::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response::_error_type arg)
  {
    msg_.error = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_USBFileSystemSubscribeSrv_Response_error();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__BUILDER_HPP_
