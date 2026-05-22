// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/USBFileSystemSubscribeSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct USBFileSystemSubscribeSrv_Request_
{
  using Type = USBFileSystemSubscribeSrv_Request_<ContainerAllocator>;

  explicit USBFileSystemSubscribeSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->file_name = "";
      this->callback_name = "";
      this->verify_name_exists = false;
    }
  }

  explicit USBFileSystemSubscribeSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : file_name(_alloc),
    callback_name(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->file_name = "";
      this->callback_name = "";
      this->verify_name_exists = false;
    }
  }

  // field types and members
  using _file_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _file_name_type file_name;
  using _callback_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _callback_name_type callback_name;
  using _verify_name_exists_type =
    bool;
  _verify_name_exists_type verify_name_exists;

  // setters for named parameter idiom
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
  Type & set__verify_name_exists(
    const bool & _arg)
  {
    this->verify_name_exists = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const USBFileSystemSubscribeSrv_Request_ & other) const
  {
    if (this->file_name != other.file_name) {
      return false;
    }
    if (this->callback_name != other.callback_name) {
      return false;
    }
    if (this->verify_name_exists != other.verify_name_exists) {
      return false;
    }
    return true;
  }
  bool operator!=(const USBFileSystemSubscribeSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct USBFileSystemSubscribeSrv_Request_

// alias to use template instance with default allocator
using USBFileSystemSubscribeSrv_Request =
  deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct USBFileSystemSubscribeSrv_Response_
{
  using Type = USBFileSystemSubscribeSrv_Response_<ContainerAllocator>;

  explicit USBFileSystemSubscribeSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error = 0l;
    }
  }

  explicit USBFileSystemSubscribeSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error = 0l;
    }
  }

  // field types and members
  using _error_type =
    int32_t;
  _error_type error;

  // setters for named parameter idiom
  Type & set__error(
    const int32_t & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__USBFileSystemSubscribeSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const USBFileSystemSubscribeSrv_Response_ & other) const
  {
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const USBFileSystemSubscribeSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct USBFileSystemSubscribeSrv_Response_

// alias to use template instance with default allocator
using USBFileSystemSubscribeSrv_Response =
  deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct USBFileSystemSubscribeSrv
{
  using Request = deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::USBFileSystemSubscribeSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__USB_FILE_SYSTEM_SUBSCRIBE_SRV__STRUCT_HPP_
