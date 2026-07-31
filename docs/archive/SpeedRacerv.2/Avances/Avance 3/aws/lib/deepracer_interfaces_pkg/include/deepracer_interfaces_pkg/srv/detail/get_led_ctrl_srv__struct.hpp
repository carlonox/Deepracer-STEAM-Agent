// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/GetLedCtrlSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetLedCtrlSrv_Request_
{
  using Type = GetLedCtrlSrv_Request_<ContainerAllocator>;

  explicit GetLedCtrlSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit GetLedCtrlSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  // field types and members
  using _structure_needs_at_least_one_member_type =
    uint8_t;
  _structure_needs_at_least_one_member_type structure_needs_at_least_one_member;


  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetLedCtrlSrv_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetLedCtrlSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetLedCtrlSrv_Request_

// alias to use template instance with default allocator
using GetLedCtrlSrv_Request =
  deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetLedCtrlSrv_Response_
{
  using Type = GetLedCtrlSrv_Response_<ContainerAllocator>;

  explicit GetLedCtrlSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red = 0l;
      this->green = 0l;
      this->blue = 0l;
    }
  }

  explicit GetLedCtrlSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->red = 0l;
      this->green = 0l;
      this->blue = 0l;
    }
  }

  // field types and members
  using _red_type =
    int32_t;
  _red_type red;
  using _green_type =
    int32_t;
  _green_type green;
  using _blue_type =
    int32_t;
  _blue_type blue;

  // setters for named parameter idiom
  Type & set__red(
    const int32_t & _arg)
  {
    this->red = _arg;
    return *this;
  }
  Type & set__green(
    const int32_t & _arg)
  {
    this->green = _arg;
    return *this;
  }
  Type & set__blue(
    const int32_t & _arg)
  {
    this->blue = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetLedCtrlSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetLedCtrlSrv_Response_ & other) const
  {
    if (this->red != other.red) {
      return false;
    }
    if (this->green != other.green) {
      return false;
    }
    if (this->blue != other.blue) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetLedCtrlSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetLedCtrlSrv_Response_

// alias to use template instance with default allocator
using GetLedCtrlSrv_Response =
  deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct GetLedCtrlSrv
{
  using Request = deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::GetLedCtrlSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_LED_CTRL_SRV__STRUCT_HPP_
