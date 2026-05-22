// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/GetCalibrationSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetCalibrationSrv_Request_
{
  using Type = GetCalibrationSrv_Request_<ContainerAllocator>;

  explicit GetCalibrationSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cal_type = 0l;
    }
  }

  explicit GetCalibrationSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->cal_type = 0l;
    }
  }

  // field types and members
  using _cal_type_type =
    int32_t;
  _cal_type_type cal_type;

  // setters for named parameter idiom
  Type & set__cal_type(
    const int32_t & _arg)
  {
    this->cal_type = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetCalibrationSrv_Request_ & other) const
  {
    if (this->cal_type != other.cal_type) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetCalibrationSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetCalibrationSrv_Request_

// alias to use template instance with default allocator
using GetCalibrationSrv_Request =
  deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct GetCalibrationSrv_Response_
{
  using Type = GetCalibrationSrv_Response_<ContainerAllocator>;

  explicit GetCalibrationSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max = 0l;
      this->mid = 0l;
      this->min = 0l;
      this->polarity = 0l;
      this->error = 0l;
    }
  }

  explicit GetCalibrationSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->max = 0l;
      this->mid = 0l;
      this->min = 0l;
      this->polarity = 0l;
      this->error = 0l;
    }
  }

  // field types and members
  using _max_type =
    int32_t;
  _max_type max;
  using _mid_type =
    int32_t;
  _mid_type mid;
  using _min_type =
    int32_t;
  _min_type min;
  using _polarity_type =
    int32_t;
  _polarity_type polarity;
  using _error_type =
    int32_t;
  _error_type error;

  // setters for named parameter idiom
  Type & set__max(
    const int32_t & _arg)
  {
    this->max = _arg;
    return *this;
  }
  Type & set__mid(
    const int32_t & _arg)
  {
    this->mid = _arg;
    return *this;
  }
  Type & set__min(
    const int32_t & _arg)
  {
    this->min = _arg;
    return *this;
  }
  Type & set__polarity(
    const int32_t & _arg)
  {
    this->polarity = _arg;
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
    deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__GetCalibrationSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const GetCalibrationSrv_Response_ & other) const
  {
    if (this->max != other.max) {
      return false;
    }
    if (this->mid != other.mid) {
      return false;
    }
    if (this->min != other.min) {
      return false;
    }
    if (this->polarity != other.polarity) {
      return false;
    }
    if (this->error != other.error) {
      return false;
    }
    return true;
  }
  bool operator!=(const GetCalibrationSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct GetCalibrationSrv_Response_

// alias to use template instance with default allocator
using GetCalibrationSrv_Response =
  deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct GetCalibrationSrv
{
  using Request = deepracer_interfaces_pkg::srv::GetCalibrationSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::GetCalibrationSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__GET_CALIBRATION_SRV__STRUCT_HPP_
