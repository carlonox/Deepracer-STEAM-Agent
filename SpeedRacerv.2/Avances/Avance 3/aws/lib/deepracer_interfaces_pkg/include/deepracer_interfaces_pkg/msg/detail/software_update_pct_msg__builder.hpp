// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/SoftwareUpdatePctMsg.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/software_update_pct_msg__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_SoftwareUpdatePctMsg_status
{
public:
  explicit Init_SoftwareUpdatePctMsg_status(::deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg status(::deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg::_status_type arg)
  {
    msg_.status = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg msg_;
};

class Init_SoftwareUpdatePctMsg_update_pct
{
public:
  Init_SoftwareUpdatePctMsg_update_pct()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_SoftwareUpdatePctMsg_status update_pct(::deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg::_update_pct_type arg)
  {
    msg_.update_pct = std::move(arg);
    return Init_SoftwareUpdatePctMsg_status(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::SoftwareUpdatePctMsg>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_SoftwareUpdatePctMsg_update_pct();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__SOFTWARE_UPDATE_PCT_MSG__BUILDER_HPP_
