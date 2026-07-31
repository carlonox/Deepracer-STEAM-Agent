// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/ConsoleModelActionSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__CONSOLE_MODEL_ACTION_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__CONSOLE_MODEL_ACTION_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConsoleModelActionSrv_Request_
{
  using Type = ConsoleModelActionSrv_Request_<ContainerAllocator>;

  explicit ConsoleModelActionSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model_path = "";
      this->action = 0l;
    }
  }

  explicit ConsoleModelActionSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : model_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model_path = "";
      this->action = 0l;
    }
  }

  // field types and members
  using _model_path_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _model_path_type model_path;
  using _action_type =
    int32_t;
  _action_type action;

  // setters for named parameter idiom
  Type & set__model_path(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->model_path = _arg;
    return *this;
  }
  Type & set__action(
    const int32_t & _arg)
  {
    this->action = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConsoleModelActionSrv_Request_ & other) const
  {
    if (this->model_path != other.model_path) {
      return false;
    }
    if (this->action != other.action) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConsoleModelActionSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConsoleModelActionSrv_Request_

// alias to use template instance with default allocator
using ConsoleModelActionSrv_Request =
  deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ConsoleModelActionSrv_Response_
{
  using Type = ConsoleModelActionSrv_Response_<ContainerAllocator>;

  explicit ConsoleModelActionSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  explicit ConsoleModelActionSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->status = "";
    }
  }

  // field types and members
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ConsoleModelActionSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ConsoleModelActionSrv_Response_ & other) const
  {
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const ConsoleModelActionSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ConsoleModelActionSrv_Response_

// alias to use template instance with default allocator
using ConsoleModelActionSrv_Response =
  deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct ConsoleModelActionSrv
{
  using Request = deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::ConsoleModelActionSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__CONSOLE_MODEL_ACTION_SRV__STRUCT_HPP_
