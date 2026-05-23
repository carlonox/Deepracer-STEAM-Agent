// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/SensorStatusCheckSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SENSOR_STATUS_CHECK_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SENSOR_STATUS_CHECK_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SensorStatusCheckSrv_Request_
{
  using Type = SensorStatusCheckSrv_Request_<ContainerAllocator>;

  explicit SensorStatusCheckSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->structure_needs_at_least_one_member = 0;
    }
  }

  explicit SensorStatusCheckSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorStatusCheckSrv_Request_ & other) const
  {
    if (this->structure_needs_at_least_one_member != other.structure_needs_at_least_one_member) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorStatusCheckSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorStatusCheckSrv_Request_

// alias to use template instance with default allocator
using SensorStatusCheckSrv_Request =
  deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SensorStatusCheckSrv_Response_
{
  using Type = SensorStatusCheckSrv_Response_<ContainerAllocator>;

  explicit SensorStatusCheckSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lidar_status = 0;
      this->single_camera_status = 0;
      this->stereo_camera_status = 0;
      this->error = 0l;
    }
  }

  explicit SensorStatusCheckSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->lidar_status = 0;
      this->single_camera_status = 0;
      this->stereo_camera_status = 0;
      this->error = 0l;
    }
  }

  // field types and members
  using _lidar_status_type =
    int8_t;
  _lidar_status_type lidar_status;
  using _single_camera_status_type =
    int8_t;
  _single_camera_status_type single_camera_status;
  using _stereo_camera_status_type =
    int8_t;
  _stereo_camera_status_type stereo_camera_status;
  using _error_type =
    int32_t;
  _error_type error;

  // setters for named parameter idiom
  Type & set__lidar_status(
    const int8_t & _arg)
  {
    this->lidar_status = _arg;
    return *this;
  }
  Type & set__single_camera_status(
    const int8_t & _arg)
  {
    this->single_camera_status = _arg;
    return *this;
  }
  Type & set__stereo_camera_status(
    const int8_t & _arg)
  {
    this->stereo_camera_status = _arg;
    return *this;
  }
  Type & set__error(
    const int32_t & _arg)
  {
    this->error = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SensorStatusCheckSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SensorStatusCheckSrv_Response_ & other) const
  {
    if (this->lidar_status != other.lidar_status) {
      return false;
    }
    if (this->single_camera_status != other.single_camera_status) {
      return false;
    }
    if (this->stereo_camera_status != other.stereo_camera_status) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const SensorStatusCheckSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SensorStatusCheckSrv_Response_

// alias to use template instance with default allocator
using SensorStatusCheckSrv_Response =
  deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct SensorStatusCheckSrv
{
  using Request = deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::SensorStatusCheckSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SENSOR_STATUS_CHECK_SRV__STRUCT_HPP_
