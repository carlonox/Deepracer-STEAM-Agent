// generated from rosidl_generator_cpp/resource/idl__builder.hpp.em
// with input from deepracer_interfaces_pkg:msg/InferResults.idl
// generated code does not contain a copyright notice

#ifndef DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__BUILDER_HPP_
#define DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__BUILDER_HPP_

#include "deepracer_interfaces_pkg/msg/detail/infer_results__struct.hpp"
#include <rosidl_runtime_cpp/message_initialization.hpp>
#include <algorithm>
#include <utility>


namespace deepracer_interfaces_pkg
{

namespace msg
{

namespace builder
{

class Init_InferResults_y_max
{
public:
  explicit Init_InferResults_y_max(::deepracer_interfaces_pkg::msg::InferResults & msg)
  : msg_(msg)
  {}
  ::deepracer_interfaces_pkg::msg::InferResults y_max(::deepracer_interfaces_pkg::msg::InferResults::_y_max_type arg)
  {
    msg_.y_max = std::move(arg);
    return std::move(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResults msg_;
};

class Init_InferResults_x_max
{
public:
  explicit Init_InferResults_x_max(::deepracer_interfaces_pkg::msg::InferResults & msg)
  : msg_(msg)
  {}
  Init_InferResults_y_max x_max(::deepracer_interfaces_pkg::msg::InferResults::_x_max_type arg)
  {
    msg_.x_max = std::move(arg);
    return Init_InferResults_y_max(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResults msg_;
};

class Init_InferResults_y_min
{
public:
  explicit Init_InferResults_y_min(::deepracer_interfaces_pkg::msg::InferResults & msg)
  : msg_(msg)
  {}
  Init_InferResults_x_max y_min(::deepracer_interfaces_pkg::msg::InferResults::_y_min_type arg)
  {
    msg_.y_min = std::move(arg);
    return Init_InferResults_x_max(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResults msg_;
};

class Init_InferResults_x_min
{
public:
  explicit Init_InferResults_x_min(::deepracer_interfaces_pkg::msg::InferResults & msg)
  : msg_(msg)
  {}
  Init_InferResults_y_min x_min(::deepracer_interfaces_pkg::msg::InferResults::_x_min_type arg)
  {
    msg_.x_min = std::move(arg);
    return Init_InferResults_y_min(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResults msg_;
};

class Init_InferResults_class_prob
{
public:
  explicit Init_InferResults_class_prob(::deepracer_interfaces_pkg::msg::InferResults & msg)
  : msg_(msg)
  {}
  Init_InferResults_x_min class_prob(::deepracer_interfaces_pkg::msg::InferResults::_class_prob_type arg)
  {
    msg_.class_prob = std::move(arg);
    return Init_InferResults_x_min(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResults msg_;
};

class Init_InferResults_class_label
{
public:
  Init_InferResults_class_label()
  : msg_(::rosidl_runtime_cpp::MessageInitialization::SKIP)
  {}
  Init_InferResults_class_prob class_label(::deepracer_interfaces_pkg::msg::InferResults::_class_label_type arg)
  {
    msg_.class_label = std::move(arg);
    return Init_InferResults_class_prob(msg_);
  }

private:
  ::deepracer_interfaces_pkg::msg::InferResults msg_;
};

}  // namespace builder

}  // namespace msg

template<typename MessageType>
auto build();

template<>
inline
auto build<::deepracer_interfaces_pkg::msg::InferResults>()
{
  return deepracer_interfaces_pkg::msg::builder::Init_InferResults_class_label();
}

}  // namespace deepracer_interfaces_pkg

#endif  // DEEPRACER_INTERFACES_PKG__MSG__DETAIL__INFER_RESULTS__BUILDER_HPP_
