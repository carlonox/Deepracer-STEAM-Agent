// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/BatteryLevelSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BATTERY_LEVEL_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BATTERY_LEVEL_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/battery_level_srv__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace srv
{


}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::BatteryLevelSrv_Request>()
{
  return ::deepracer_interfaces_pkg::srv::BatteryLevelSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_BatteryLevelSrv_Response_level
{
public:
  Init_BatteryLevelSrv_Response_level()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::BatteryLevelSrv_Response level(::deepracer_interfaces_pkg::srv::BatteryLevelSrv_Response::_level_type arg)
  {
    msg_.level = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::BatteryLevelSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::BatteryLevelSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_BatteryLevelSrv_Response_level();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__BATTERY_LEVEL_SRV__BUILDER_HPP_
