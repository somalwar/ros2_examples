#ifndef MINIMAL_COMPOSITION__PUBLISHER_NODE_HPP_
#define MINIMAL_COMPOSITION__PUBLISHER_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "visibility.h"

class PublisherNode : public rclcpp::Node
{
public:
  MINIMAL_COMPOSITION_PUBLIC PublisherNode(rclcpp::NodeOptions options);

private:
  void on_timer();
  size_t count_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
  rclcpp::TimerBase::SharedPtr timer_;
};

#endif  // MINIMAL_COMPOSITION__PUBLISHER_NODE_HPP_
