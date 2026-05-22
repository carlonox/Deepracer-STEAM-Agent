// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:msg/InferResults.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__msg__InferResults __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__msg__InferResults __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InferResults_
{
  using Type = InferResults_<ContainerAllocator>;

  explicit InferResults_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_label = 0l;
      this->class_prob = 0.0f;
      this->x_min = 0.0f;
      this->y_min = 0.0f;
      this->x_max = 0.0f;
      this->y_max = 0.0f;
    }
  }

  explicit InferResults_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->class_label = 0l;
      this->class_prob = 0.0f;
      this->x_min = 0.0f;
      this->y_min = 0.0f;
      this->x_max = 0.0f;
      this->y_max = 0.0f;
    }
  }

  // field types and members
  using _class_label_type =
    int32_t;
  _class_label_type class_label;
  using _class_prob_type =
    float;
  _class_prob_type class_prob;
  using _x_min_type =
    float;
  _x_min_type x_min;
  using _y_min_type =
    float;
  _y_min_type y_min;
  using _x_max_type =
    float;
  _x_max_type x_max;
  using _y_max_type =
    float;
  _y_max_type y_max;

  // setters for named parameter idiom
  Type & set__class_label(
    const int32_t & _arg)
  {
    this->class_label = _arg;
    return *this;
  }
  Type & set__class_prob(
    const float & _arg)
  {
    this->class_prob = _arg;
    return *this;
  }
  Type & set__x_min(
    const float & _arg)
  {
    this->x_min = _arg;
    return *this;
  }
  Type & set__y_min(
    const float & _arg)
  {
    this->y_min = _arg;
    return *this;
  }
  Type & set__x_max(
    const float & _arg)
  {
    this->x_max = _arg;
    return *this;
  }
  Type & set__y_max(
    const float & _arg)
  {
    this->y_max = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__InferResults
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__InferResults
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InferResults_ & other) const
  {
    if (this->class_label != other.class_label) {
      return false;
    }
    if (this->class_prob != other.class_prob) {
      return false;
    }
    if (this->x_min != other.x_min) {
      return false;
    }
    if (this->y_min != other.y_min) {
      return false;
    }
    if (this->x_max != other.x_max) {
      return false;
    }
    if (this->y_max != other.y_max) {
      return false;
    }
    return true;
  }
  bool operator!=(const InferResults_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InferResults_

// alias to use template instance with default allocator
using InferResults =
  deepracer_interfaces_pkg::msg::InferResults_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__STRUCT_HPP_
