// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:msg/InferResultsArray.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'results'
#include "deepracer_interfaces_pkg/msg/detail/infer_results__struct.hpp"
// Member 'images'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__msg__InferResultsArray __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__msg__InferResultsArray __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct InferResultsArray_
{
  using Type = InferResultsArray_<ContainerAllocator>;

  explicit InferResultsArray_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit InferResultsArray_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _results_type =
    std::vector<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>, typename ContainerAllocator::template rebind<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>>::other>;
  _results_type results;
  using _images_type =
    std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename ContainerAllocator::template rebind<sensor_msgs::msg::Image_<ContainerAllocator>>::other>;
  _images_type images;

  // setters for named parameter idiom
  Type & set__results(
    const std::vector<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>, typename ContainerAllocator::template rebind<deepracer_interfaces_pkg::msg::InferResults_<ContainerAllocator>>::other> & _arg)
  {
    this->results = _arg;
    return *this;
  }
  Type & set__images(
    const std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename ContainerAllocator::template rebind<sensor_msgs::msg::Image_<ContainerAllocator>>::other> & _arg)
  {
    this->images = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__InferResultsArray
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__InferResultsArray
    std::shared_ptr<deepracer_interfaces_pkg::msg::InferResultsArray_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const InferResultsArray_ & other) const
  {
    if (this->results != other.results) {
      return false;
    }
    if (this->images != other.images) {
      return false;
    }
    return true;
  }
  bool operator!=(const InferResultsArray_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct InferResultsArray_

// alias to use template instance with default allocator
using InferResultsArray =
  deepracer_interfaces_pkg::msg::InferResultsArray_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS_ARRAY__STRUCT_HPP_
