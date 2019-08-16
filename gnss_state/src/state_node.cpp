#include <chrono>

#include "../include/gnss_state/state_node.hpp"
#include "std_msgs/msg/string.hpp" //#include "gnss_state/msg/state.hpp"
#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "sensor_msgs/msg/imu.hpp"

using namespace std::chrono_literals;

GnssStateNode::GnssStateNode(rclcpp::NodeOptions options)
: Node("gnss_state_node", options)
{
    sat_subscription_ = create_subscription<sensor_msgs::msg::NavSatFix>(
        "navsatfix_topic", 10, [this](sensor_msgs::msg::NavSatFix::UniquePtr msg) {
        RCLCPP_INFO(this->get_logger(), "I heard on navsatfix_topic");
        });
    imu_subscription_ = create_subscription<sensor_msgs::msg::Imu>(
        "imu_topic", 10, [this](sensor_msgs::msg::Imu::UniquePtr msg) {
        RCLCPP_INFO(this->get_logger(), "I heard on imu_topic");
        });
    publisher_ = create_publisher<std_msgs::msg::String>("state_topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&GnssStateNode::publisher_callback, this));
}

void GnssStateNode::publisher_callback()
{
    auto message = std_msgs::msg::String();
    message.data = "Publishing on to state_topic";
    RCLCPP_INFO(this->get_logger(), "%s", message.data.c_str());
    publisher_->publish(message);
}
