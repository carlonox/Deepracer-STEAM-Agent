// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:srv/OTGLinkStateSrv.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__SRV__DETAIL__OTG_LINK_STATE_SRV__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__SRV__DETAIL__OTG_LINK_STATE_SRV__BUILDER_HPP_

#include "deepracer_interfaces_pkg/srv/detail/otg_link_state_srv__struct.hpp"
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
auto build<::deepracer_interfaces_pkg::srv::OTGLinkStateSrv_Request>()
{
  return ::deepracer_interfaces_pkg::srv::OTGLinkStateSrv_Request(rosidl_runtime_cpp::MessageInitialization::ZERO);
}

}  // namespace deepracer_interfaces_pkg


namespace deepracer_interfaces_pkg
{

namespace srv
{

namespace builder
{

class Init_OTGLinkStateSrv_Response_link_state
{
public:
  Init_OTGLinkStateSrv_Response_link_state()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  ::deepracer_interfaces_pkg::srv::OTGLinkStateSrv_Response link_state(::deepracer_interfaces_pkg::srv::OTGLinkStateSrv_Response::_link_state_type arg)
  {
    msg_.link_state = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::srv::OTGLinkStateSrv_Response msg_;
};

}  // namespace builder

}  // namespace srv

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::srv::OTGLinkStateSrv_Response>()
{
  return deepracer_interfaces_pkg::srv::builder::Init_OTGLinkStateSrv_Response_link_state();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__SRV__DETAIL__OTG_LINK_STATE_SRV__BUILDER_HPP_
