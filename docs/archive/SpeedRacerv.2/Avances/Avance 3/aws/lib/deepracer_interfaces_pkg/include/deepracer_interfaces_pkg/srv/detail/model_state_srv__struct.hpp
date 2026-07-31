// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/ModelStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_STATE_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_STATE_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ModelStateSrv_Request_
{
  using Type = ModelStateSrv_Request_<ContainerAllocator>;

  explicit ModelStateSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model_name = "";
      this->training_algorithm = 0;
      this->action_space_type = 0;
      this->img_format = "";
      this->width = 0l;
      this->height = 0l;
      this->num_channels = 0l;
      this->lidar_channels = 0l;
      this->platform = 0l;
      this->task_type = 0;
      this->pre_process_type = 0;
    }
  }

  explicit ModelStateSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  : model_name(_alloc),
    img_format(_alloc)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->model_name = "";
      this->training_algorithm = 0;
      this->action_space_type = 0;
      this->img_format = "";
      this->width = 0l;
      this->height = 0l;
      this->num_channels = 0l;
      this->lidar_channels = 0l;
      this->platform = 0l;
      this->task_type = 0;
      this->pre_process_type = 0;
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
    int8_t;
  _training_algorithm_type training_algorithm;
  using _action_space_type_type =
    int8_t;
  _action_space_type_type action_space_type;
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
  using _task_type_type =
    int8_t;
  _task_type_type task_type;
  using _pre_process_type_type =
    int8_t;
  _pre_process_type_type pre_process_type;

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
    const int8_t & _arg)
  {
    this->training_algorithm = _arg;
    return *this;
  }
  Type & set__action_space_type(
    const int8_t & _arg)
  {
    this->action_space_type = _arg;
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
  Type & set__task_type(
    const int8_t & _arg)
  {
    this->task_type = _arg;
    return *this;
  }
  Type & set__pre_process_type(
    const int8_t & _arg)
  {
    this->pre_process_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModelStateSrv_Request_ & other) const
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
    if (this->action_space_type != other.action_space_type) {
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
    if (this->task_type != other.task_type) {
      return false;
    }
    if (this->pre_process_type != other.pre_process_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModelStateSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModelStateSrv_Request_

// alias to use template instance with default allocator
using ModelStateSrv_Request =
  deepracer_interfaces_pkg::srv::ModelStateSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct ModelStateSrv_Response_
{
  using Type = ModelStateSrv_Response_<ContainerAllocator>;

  explicit ModelStateSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->error = 0l;
    }
  }

  explicit ModelStateSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
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
    deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__ModelStateSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const ModelStateSrv_Response_ & other) const
  {
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const ModelStateSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct ModelStateSrv_Response_

// alias to use template instance with default allocator
using ModelStateSrv_Response =
  deepracer_interfaces_pkg::srv::ModelStateSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct ModelStateSrv
{
  using Request = deepracer_interfaces_pkg::srv::ModelStateSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::ModelStateSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__MODEL_STATE_SRV__STRUCT_HPP_
