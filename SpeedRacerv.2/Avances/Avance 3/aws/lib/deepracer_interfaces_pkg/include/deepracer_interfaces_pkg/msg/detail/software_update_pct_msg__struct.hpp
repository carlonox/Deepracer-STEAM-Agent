// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:msg/SoftwareUpdatePctMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct SoftwareUpdatePctMsg_
{
  using Type = SoftwareUpdatePctMsg_<ContainerAllocator>;

  explicit SoftwareUpdatePctMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->update_pct = 0.0f;
      this->status = "";
    }
  }

  explicit SoftwareUpdatePctMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : status(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->update_pct = 0.0f;
      this->status = "";
    }
  }

  // field types and members
  using _update_pct_type =
    float;
  _update_pct_type update_pct;
  using _status_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _status_type status;

  // setters for named parameter idiom
  Type & set__update_pct(
    const float & _arg)
  {
    this->update_pct = _arg;
    return *this;
  }
  Type & set__status(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__SoftwareUpdatePctMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SoftwareUpdatePctMsg_ & other) const
  {
    if (this->update_pct != other.update_pct) {
      return false;
    }
    if (this->status != other.status) {
      return false;
    }
    return true;
  }
  bool operator!=(const SoftwareUpdatePctMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SoftwareUpdatePctMsg_

// alias to use template instance with default allocator
using SoftwareUpdatePctMsg =
  deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__STRUCT_HPP_
