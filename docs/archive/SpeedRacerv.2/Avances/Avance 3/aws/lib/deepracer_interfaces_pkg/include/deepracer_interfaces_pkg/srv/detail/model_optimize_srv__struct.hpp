// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/ModelOptimizeSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ModelOptimizeSrv_Request_
{
  using Type = ModelOptimizeSrv_Request_<ContainerAllocator>;

  explicit ModelOptimizeSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model_name = "";
      this->training_algorithm = 0l;
      this->img_format = "";
      this->width = 0l;
      this->height = 0l;
      this->num_channels = 0l;
      this->lidar_channels = 0l;
      this->platform = 0l;
    }
  }

  explicit ModelOptimizeSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : model_name(_alloc),
    img_format(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model_name = "";
      this->training_algorithm = 0l;
      this->img_format = "";
      this->width = 0l;
      this->height = 0l;
      this->num_channels = 0l;
      this->lidar_channels = 0l;
      this->platform = 0l;
    }
  }

  // field types and members
  using _model_name_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _model_name_type model_name;
  using _model_metadata_sensors_type =
    std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other>;
  _model_metadata_sensors_type model_metadata_sensors;
  using _training_algorithm_type =
    int32_t;
  _training_algorithm_type training_algorithm;
  using _img_format_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _img_format_type img_format;
  using _width_type =
    int32_t;
  _width_type width;
  using _height_type =
    int32_t;
  _height_type height;
  using _num_channels_type =
    int32_t;
  _num_channels_type num_channels;
  using _lidar_channels_type =
    int32_t;
  _lidar_channels_type lidar_channels;
  using _platform_type =
    int32_t;
  _platform_type platform;

  // setters for named parameter idiom
  Type & set__model_name(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->model_name = _arg;
    return *this;
  }
  Type & set__model_metadata_sensors(
    const std::vector<int32_t, typename ContainerAllocator::template rebind<int32_t>::other> & _arg)
  {
    this->model_metadata_sensors = _arg;
    return *this;
  }
  Type & set__training_algorithm(
    const int32_t & _arg)
  {
    this->training_algorithm = _arg;
    return *this;
  }
  Type & set__img_format(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->img_format = _arg;
    return *this;
  }
  Type & set__width(
    const int32_t & _arg)
  {
    this->width = _arg;
    return *this;
  }
  Type & set__height(
    const int32_t & _arg)
  {
    this->height = _arg;
    return *this;
  }
  Type & set__num_channels(
    const int32_t & _arg)
  {
    this->num_channels = _arg;
    return *this;
  }
  Type & set__lidar_channels(
    const int32_t & _arg)
  {
    this->lidar_channels = _arg;
    return *this;
  }
  Type & set__platform(
    const int32_t & _arg)
  {
    this->platform = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModelOptimizeSrv_Request_ & other) const
  {
    if (this->model_name != other.model_name) {
      return false;
    }
    if (this->model_metadata_sensors != other.model_metadata_sensors) {
      return false;
    }
    if (this->training_algorithm != other.training_algorithm) {
      return false;
    }
    if (this->img_format != other.img_format) {
      return false;
    }
    if (this->width != other.width) {
      return false;
    }
    if (this->height != other.height) {
      return false;
    }
    if (this->num_channels != other.num_channels) {
      return false;
    }
    if (this->lidar_channels != other.lidar_channels) {
      return false;
    }
    if (this->platform != other.platform) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModelOptimizeSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModelOptimizeSrv_Request_

// alias to use template instance with default allocator
using ModelOptimizeSrv_Request =
  deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ModelOptimizeSrv_Response_
{
  using Type = ModelOptimizeSrv_Response_<ContainerAllocator>;

  explicit ModelOptimizeSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->artifact_path = "";
      this->error = 0l;
    }
  }

  explicit ModelOptimizeSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : artifact_path(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->artifact_path = "";
      this->error = 0l;
    }
  }

  // field types and members
  using _artifact_path_type =
    std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other>;
  _artifact_path_type artifact_path;
  using _error_type =
    int32_t;
  _error_type error;

  // setters for named parameter idiom
  Type & set__artifact_path(
    const std::basic_string<char, std::char_traits<char>, typename ContainerAllocator::template rebind<char>::other> & _arg)
  {
    this->artifact_path = _arg;
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
    deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelOptimizeSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModelOptimizeSrv_Response_ & other) const
  {
    if (this->artifact_path != other.artifact_path) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModelOptimizeSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModelOptimizeSrv_Response_

// alias to use template instance with default allocator
using ModelOptimizeSrv_Response =
  deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct ModelOptimizeSrv
{
  using Request = deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::ModelOptimizeSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_OPTIMIZE_SRV__STRUCT_HPP_
