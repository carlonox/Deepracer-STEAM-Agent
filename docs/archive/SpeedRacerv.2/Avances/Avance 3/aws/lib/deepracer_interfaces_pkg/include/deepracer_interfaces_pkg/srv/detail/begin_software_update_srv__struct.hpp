// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/BeginSoftwareUpdateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BeginSoftwareUpdateSrv_Request_
{
  using Type = BeginSoftwareUpdateSrv_Request_<ContainerAllocator>;

  explicit BeginSoftwareUpdateSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sleep_time_before_reboot = 0l;
    }
  }

  explicit BeginSoftwareUpdateSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->sleep_time_before_reboot = 0l;
    }
  }

  // field types and members
  using _sleep_time_before_reboot_type =
    int32_t;
  _sleep_time_before_reboot_type sleep_time_before_reboot;

  // setters for named parameter idiom
  Type & set__sleep_time_before_reboot(
    const int32_t & _arg)
  {
    this->sleep_time_before_reboot = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BeginSoftwareUpdateSrv_Request_ & other) const
  {
    if (this->sleep_time_before_reboot != other.sleep_time_before_reboot) {
      return false;
    }
    return true;
  }
  bool operator!=(const BeginSoftwareUpdateSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BeginSoftwareUpdateSrv_Request_

// alias to use template instance with default allocator
using BeginSoftwareUpdateSrv_Request =
  deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct BeginSoftwareUpdateSrv_Response_
{
  using Type = BeginSoftwareUpdateSrv_Response_<ContainerAllocator>;

  explicit BeginSoftwareUpdateSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response_status = false;
    }
  }

  explicit BeginSoftwareUpdateSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->response_status = false;
    }
  }

  // field types and members
  using _response_status_type =
    bool;
  _response_status_type response_status;

  // setters for named parameter idiom
  Type & set__response_status(
    const bool & _arg)
  {
    this->response_status = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__BeginSoftwareUpdateSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const BeginSoftwareUpdateSrv_Response_ & other) const
  {
    if (this->response_status != other.response_status) {
      return false;
    }
    return true;
  }
  bool operator!=(const BeginSoftwareUpdateSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct BeginSoftwareUpdateSrv_Response_

// alias to use template instance with default allocator
using BeginSoftwareUpdateSrv_Response =
  deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct BeginSoftwareUpdateSrv
{
  using Request = deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::BeginSoftwareUpdateSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BEGIN_SOFTWARE_UPDATE_SRV__STRUCT_HPP_
