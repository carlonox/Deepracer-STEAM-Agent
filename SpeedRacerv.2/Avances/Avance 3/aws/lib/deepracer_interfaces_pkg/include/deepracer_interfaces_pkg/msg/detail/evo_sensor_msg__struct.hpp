// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:msg/EvoSensorMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


// Include directives for member types
// Member 'images'
#include "sensor_msgs/msg/detail/image__struct.hpp"

#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__msg__EvoSensorMsg __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__msg__EvoSensorMsg __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace msg
{

// message struct
template<class ContainerAllocator>
struct EvoSensorMsg_
{
  using Type = EvoSensorMsg_<ContainerAllocator>;

  explicit EvoSensorMsg_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
  }

  explicit EvoSensorMsg_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_init;
    (void)_alloc;
  }

  // field types and members
  using _images_type =
    std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename ContainerAllocator::template rebind<sensor_msgs::msg::Image_<ContainerAllocator>>::other>;
  _images_type images;
  using _lidar_data_type =
    std::vector<float, typename ContainerAllocator::template rebind<float>::other>;
  _lidar_data_type lidar_data;

  // setters for named parameter idiom
  Type & set__images(
    const std::vector<sensor_msgs::msg::Image_<ContainerAllocator>, typename ContainerAllocator::template rebind<sensor_msgs::msg::Image_<ContainerAllocator>>::other> & _arg)
  {
    this->images = _arg;
    return *this;
  }
  Type & set__lidar_data(
    const std::vector<float, typename ContainerAllocator::template rebind<float>::other> & _arg)
  {
    this->lidar_data = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__EvoSensorMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__msg__EvoSensorMsg
    std::shared_ptr<deepracer_interfaces_pkg::msg::EvoSensorMsg_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const EvoSensorMsg_ & other) const
  {
    if (this->images != other.images) {
      return false;
    }
    if (this->lidar_data != other.lidar_data) {
      return false;
    }
    return true;
  }
  bool operator!=(const EvoSensorMsg_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct EvoSensorMsg_

// alias to use template instance with default allocator
using EvoSensorMsg =
  deepracer_interfaces_pkg::msg::EvoSensorMsg_<std::allocator<void>>;

// constant definitions

}  // namespace msg

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__EVO_SENSOR_MSG__STRUCT_HPP_
