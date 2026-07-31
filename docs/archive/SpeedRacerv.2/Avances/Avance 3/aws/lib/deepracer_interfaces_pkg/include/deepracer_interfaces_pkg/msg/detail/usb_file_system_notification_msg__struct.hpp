// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:msg/USBFileSystemNotificationMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct USBFileSystemNotificationMsg_
{
  using Type = USBFileSystemNotificationMsg_<ContainerAllocator>;

  explicit USBFileSystemNotificationMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path = "";
      this->file_name = "";
      this->callback_name = "";
      this->node_name = "";
    }
  }

  explicit USBFileSystemNotificationMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : path(_alloc),
    file_name(_alloc),
    callback_name(_alloc),
    node_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->path = "";
      this->file_name = "";
      this->callback_name = "";
      this->node_name = "";
    }
  }

  // field types and members
  using _path_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _path_type path;
  using _file_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _file_name_type file_name;
  using _callback_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _callback_name_type callback_name;
  using _node_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _node_name_type node_name;

  // setters for named parameter idiom
  Type & set__path(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->path = _arg;
    return *this;
  }
  Type & set__file_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->file_name = _arg;
    return *this;
  }
  Type & set__callback_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->callback_name = _arg;
    return *this;
  }
  Type & set__node_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->node_name = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__USBFileSystemNotificationMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const USBFileSystemNotificationMsg_ & other) const
  {
    if (this->path != other.path) {
      return false;
    }
    if (this->file_name != other.file_name) {
      return false;
    }
    if (this->callback_name != other.callback_name) {
      return false;
    }
    if (this->node_name != other.node_name) {
      return false;
    }
    return true;
  }
  bool operator!=(const USBFileSystemNotificationMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct USBFileSystemNotificationMsg_

// alias to use template instance with default allocator
using USBFileSystemNotificationMsg =
  deepracer_interfaces_pkg::msg::USBFileSystemNotificationMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__USB_FILE_SYSTEM_NOTIFICATION_MSG__STRUCT_HPP_
