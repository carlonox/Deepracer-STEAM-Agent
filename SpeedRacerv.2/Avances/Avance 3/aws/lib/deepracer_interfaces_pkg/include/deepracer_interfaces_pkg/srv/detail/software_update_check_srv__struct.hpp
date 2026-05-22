// generated from rosidl_generator_cpp/resource/idl__struct.hpp.em
// with input from deepracer_interfaces_pkg:srv/SoftwareUpdateCheckSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__STRUCT_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__STRUCT_HPP_

#include <rosidl_runtime_cpp/bounded_vector.hpp>
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <array>
#include <memory>
#include <string>
#include <vector>


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SoftwareUpdateCheckSrv_Request_
{
  using Type = SoftwareUpdateCheckSrv_Request_<ContainerAllocator>;

  explicit SoftwareUpdateCheckSrv_Request_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_update_check = 0l;
    }
  }

  explicit SoftwareUpdateCheckSrv_Request_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->force_update_check = 0l;
    }
  }

  // field types and members
  using _force_update_check_type =
    int32_t;
  _force_update_check_type force_update_check;

  // setters for named parameter idiom
  Type & set__force_update_check(
    const int32_t & _arg)
  {
    this->force_update_check = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Request
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SoftwareUpdateCheckSrv_Request_ & other) const
  {
    if (this->force_update_check != other.force_update_check) {
      return false;
    }
    return true;
  }
  bool operator!=(const SoftwareUpdateCheckSrv_Request_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SoftwareUpdateCheckSrv_Request_

// alias to use template instance with default allocator
using SoftwareUpdateCheckSrv_Request =
  deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg


#ifndef _WIN32
# define DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response __attribute__((deprecated))
#else
# define DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response __declspec(deprecated)
#endif

namespace deepracer_interfaces_pkg
{

namespace srv
{

// message struct
template<class ContainerAllocator>
struct SoftwareUpdateCheckSrv_Response_
{
  using Type = SoftwareUpdateCheckSrv_Response_<ContainerAllocator>;

  explicit SoftwareUpdateCheckSrv_Response_(rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->software_update_state = 0l;
    }
  }

  explicit SoftwareUpdateCheckSrv_Response_(const ContainerAllocator & _alloc, rosidl_runtime_cpp::MessageInitialization _init = rosidl_runtime_cpp::MessageInitialization::ALL)
  {
    (void)_alloc;
    if (rosidl_runtime_cpp::MessageInitialization::ALL == _init ||
      rosidl_runtime_cpp::MessageInitialization::ZERO == _init)
    {
      this->software_update_state = 0l;
    }
  }

  // field types and members
  using _software_update_state_type =
    int32_t;
  _software_update_state_type software_update_state;

  // setters for named parameter idiom
  Type & set__software_update_state(
    const int32_t & _arg)
  {
    this->software_update_state = _arg;
    return *this;
  }

  // constant declarations

  // pointer types
  using RawPtr =
    deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator> *;
  using ConstRawPtr =
    const deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator> *;
  using SharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator>>;
  using ConstSharedPtr =
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator> const>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator>>>
  using UniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator>, Deleter>;

  using UniquePtr = UniquePtrWithDeleter<>;

  template<typename Deleter = std::default_delete<
      deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator>>>
  using ConstUniquePtrWithDeleter =
    std::unique_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator> const, Deleter>;
  using ConstUniquePtr = ConstUniquePtrWithDeleter<>;

  using WeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator>>;
  using ConstWeakPtr =
    std::weak_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator> const>;

  // pointer types similar to ROS 1, use SharedPtr / ConstSharedPtr instead
  // NOTE: Can't use 'using' here because GNU C++ can't parse attributes properly
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator>>
    Ptr;
  typedef DEPRECATED__deepracer_interfaces_pkg__srv__SoftwareUpdateCheckSrv_Response
    std::shared_ptr<deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<ContainerAllocator> const>
    ConstPtr;

  // comparison operators
  bool operator==(const SoftwareUpdateCheckSrv_Response_ & other) const
  {
    if (this->software_update_state != other.software_update_state) {
      return false;
    }
    return true;
  }
  bool operator!=(const SoftwareUpdateCheckSrv_Response_ & other) const
  {
    return !this->operator==(other);
  }
};  // struct SoftwareUpdateCheckSrv_Response_

// alias to use template instance with default allocator
using SoftwareUpdateCheckSrv_Response =
  deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response_<std::allocator<void>>;

// constant definitions

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

namespace deepracer_interfaces_pkg
{

namespace srv
{

struct SoftwareUpdateCheckSrv
{
  using Request = deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Request;
  using Response = deepracer_interfaces_pkg::srv::SoftwareUpdateCheckSrv_Response;
};

}  // namespace srv

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__SOFTWARE_UPDATE_CHECK_SRV__STRUCT_HPP_
