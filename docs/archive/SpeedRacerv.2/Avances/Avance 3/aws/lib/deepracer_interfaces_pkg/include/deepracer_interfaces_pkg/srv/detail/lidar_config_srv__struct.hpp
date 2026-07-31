// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/LidarConfigSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LIDAR_CONFIG_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LIDAR_CONFIG_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LidarConfigSrv_Request_
{
  using Type = LidarConfigSrv_Request_<ContainerAllocator>;

  explicit LidarConfigSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->use_lidar = false;
      this->min_angle = 0.0f;
      this->max_angle = 0.0f;
      this->num_values = 0l;
      this->min_distance = 0.0f;
      this->max_distance = 0.0f;
      this->clipping_distance = 0.0f;
      this->num_sectors = 0l;
      this->preprocess_type = 0;
    }
  }

  explicit LidarConfigSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->use_lidar = false;
      this->min_angle = 0.0f;
      this->max_angle = 0.0f;
      this->num_values = 0l;
      this->min_distance = 0.0f;
      this->max_distance = 0.0f;
      this->clipping_distance = 0.0f;
      this->num_sectors = 0l;
      this->preprocess_type = 0;
    }
  }

  // field types and members
  using _use_lidar_type =
    bool;
  _use_lidar_type use_lidar;
  using _min_angle_type =
    float;
  _min_angle_type min_angle;
  using _max_angle_type =
    float;
  _max_angle_type max_angle;
  using _num_values_type =
    int32_t;
  _num_values_type num_values;
  using _min_distance_type =
    float;
  _min_distance_type min_distance;
  using _max_distance_type =
    float;
  _max_distance_type max_distance;
  using _clipping_distance_type =
    float;
  _clipping_distance_type clipping_distance;
  using _num_sectors_type =
    int32_t;
  _num_sectors_type num_sectors;
  using _preprocess_type_type =
    int8_t;
  _preprocess_type_type preprocess_type;

  // setters for named parameter idiom
  Type & set__use_lidar(
    const bool & _arg)
  {
    this->use_lidar = _arg;
    return *this;
  }
  Type & set__min_angle(
    const float & _arg)
  {
    this->min_angle = _arg;
    return *this;
  }
  Type & set__max_angle(
    const float & _arg)
  {
    this->max_angle = _arg;
    return *this;
  }
  Type & set__num_values(
    const int32_t & _arg)
  {
    this->num_values = _arg;
    return *this;
  }
  Type & set__min_distance(
    const float & _arg)
  {
    this->min_distance = _arg;
    return *this;
  }
  Type & set__max_distance(
    const float & _arg)
  {
    this->max_distance = _arg;
    return *this;
  }
  Type & set__clipping_distance(
    const float & _arg)
  {
    this->clipping_distance = _arg;
    return *this;
  }
  Type & set__num_sectors(
    const int32_t & _arg)
  {
    this->num_sectors = _arg;
    return *this;
  }
  Type & set__preprocess_type(
    const int8_t & _arg)
  {
    this->preprocess_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarConfigSrv_Request_ & other) const
  {
    if (this->use_lidar != other.use_lidar) {
      return false;
    }
    if (this->min_angle != other.min_angle) {
      return false;
    }
    if (this->max_angle != other.max_angle) {
      return false;
    }
    if (this->num_values != other.num_values) {
      return false;
    }
    if (this->min_distance != other.min_distance) {
      return false;
    }
    if (this->max_distance != other.max_distance) {
      return false;
    }
    if (this->clipping_distance != other.clipping_distance) {
      return false;
    }
    if (this->num_sectors != other.num_sectors) {
      return false;
    }
    if (this->preprocess_type != other.preprocess_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarConfigSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarConfigSrv_Request_

// alias to use template instance with default allocator
using LidarConfigSrv_Request =
  deepracer_interfaces_pkg::srv::LidarConfigSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct LidarConfigSrv_Response_
{
  using Type = LidarConfigSrv_Response_<ContainerAllocator>;

  explicit LidarConfigSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error = 0l;
    }
  }

  explicit LidarConfigSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__LidarConfigSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const LidarConfigSrv_Response_ & other) const
  {
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const LidarConfigSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct LidarConfigSrv_Response_

// alias to use template instance with default allocator
using LidarConfigSrv_Response =
  deepracer_interfaces_pkg::srv::LidarConfigSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct LidarConfigSrv
{
  using Request = deepracer_interfaces_pkg::srv::LidarConfigSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::LidarConfigSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__LIDAR_CONFIG_SRV__STRUCT_HPP_
