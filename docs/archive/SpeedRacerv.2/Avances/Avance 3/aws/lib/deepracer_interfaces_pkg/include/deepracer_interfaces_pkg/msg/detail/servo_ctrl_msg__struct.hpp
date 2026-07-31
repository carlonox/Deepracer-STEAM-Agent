// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:msg/ServoCtrlMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__msg__ServoCtrlMsg __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__msg__ServoCtrlMsg __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct ServoCtrlMsg_
{
  using Type = ServoCtrlMsg_<ContainerAllocator>;

  explicit ServoCtrlMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0.0f;
      this->throttle = 0.0f;
    }
  }

  explicit ServoCtrlMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->angle = 0.0f;
      this->throttle = 0.0f;
    }
  }

  // field types and members
  using _angle_type =
    float;
  _angle_type angle;
  using _throttle_type =
    float;
  _throttle_type throttle;

  // setters for named parameter idiom
  Type & set__angle(
    const float & _arg)
  {
    this->angle = _arg;
    return *this;
  }
  Type & set__throttle(
    const float & _arg)
  {
    this->throttle = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__ServoCtrlMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__ServoCtrlMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::ServoCtrlMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ServoCtrlMsg_ & other) const
  {
    if (this->angle != other.angle) {
      return false;
    }
    if (this->throttle != other.throttle) {
      return false;
    }
    return true;
  }
  bool operator!=(const ServoCtrlMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ServoCtrlMsg_

// alias to use template instance with default allocator
using ServoCtrlMsg =
  deepracer_interfaces_pkg::msg::ServoCtrlMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SERVO_CTRL_MSG__STRUCT_HPP_
