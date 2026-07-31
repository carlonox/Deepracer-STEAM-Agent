// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/USBFileSystemNotificationMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/usb_file_system_notification_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_USBFileSystemNotificationMsg_node_name
{
public:
  explicit Init_USBFileSystemNotificationMsg_node_name(::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg node_name(::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg::_node_name_type arg)
  {
    msg_.node_name = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg msg_;
};

class Init_USBFileSystemNotificationMsg_callback_name
{
public:
  explicit Init_USBFileSystemNotificationMsg_callback_name(::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg & msg)
  : msg_(msg)
  {}
  Init_USBFileSystemNotificationMsg_node_name callback_name(::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg::_callback_name_type arg)
  {
    msg_.callback_name = std::move(arg);
    return Init_USBFileSystemNotificationMsg_node_name(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg msg_;
};

class Init_USBFileSystemNotificationMsg_file_name
{
public:
  explicit Init_USBFileSystemNotificationMsg_file_name(::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg & msg)
  : msg_(msg)
  {}
  Init_USBFileSystemNotificationMsg_callback_name file_name(::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg::_file_name_type arg)
  {
    msg_.file_name = std::move(arg);
    return Init_USBFileSystemNotificationMsg_callback_name(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg msg_;
};

class Init_USBFileSystemNotificationMsg_path
{
public:
  Init_USBFileSystemNotificationMsg_path()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_USBFileSystemNotificationMsg_file_name path(::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg::_path_type arg)
  {
    msg_.path = std::move(arg);
    return Init_USBFileSystemNotificationMsg_file_name(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_USBFileSystemNotificationMsg_path();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__BUILDER_HPP_
