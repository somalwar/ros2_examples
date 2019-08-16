#include <chrono>

#include "../include/gnss_state/state_node.hpp"
#include "std_msgs/msg/string.hpp"
#include "gnss_state/msg/state.hpp"
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
        nav_sat_msg_ = *msg;
        });
    imu_subscription_ = create_subscription<sensor_msgs::msg::Imu>(
        "imu_topic", 10, [this](sensor_msgs::msg::Imu::UniquePtr msg) {
        RCLCPP_INFO(this->get_logger(), "I heard on imu_topic");
        imu_msg_ = *msg;
        });
    publisher_ = create_publisher<gnss_state::msg::State>("state_topic", 10);
    timer_ = this->create_wall_timer(500ms, std::bind(&GnssStateNode::publisher_callback, this));
}

void GnssStateNode::publisher_callback()
{
    auto message = gnss_state::msg::State();
    message.x = nav_sat_msg_.longitude;
    message.y = nav_sat_msg_.latitude;
    message.z = nav_sat_msg_.altitude;
    message.roll = imu_msg_.orientation.x;
    message.pitch = imu_msg_.orientation.y;
    message.yaw = imu_msg_.orientation.z;
    //message.linear_velocity = 
    message.angular_velocity.z = imu_msg_.angular_velocity.z;
    //message.linear_acceleration = 
    message.angular_acceleration.z = imu_msg_.linear_acceleration.z;

    RCLCPP_INFO(this->get_logger(), "Publishing message onto state_topic");
    publisher_->publish(message);
}
