#ifndef GNSS_STATE_STATE_NODE_HPP_
#define GNSS_STATE_STATE_NODE_HPP_

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"
#include "gnss_state/msg/state.hpp"
#include "sensor_msgs/msg/nav_sat_fix.hpp"
#include "sensor_msgs/msg/imu.hpp"
#include "visibility.h"


class GnssStateNode : public rclcpp::Node
{
    public:
    GNSS_STATE_PUBLIC GnssStateNode(rclcpp::NodeOptions options);

    private:
    void publisher_callback();
    rclcpp::Publisher<gnss_state::msg::State>::SharedPtr publisher_;
    rclcpp::Subscription<sensor_msgs::msg::NavSatFix>::SharedPtr sat_subscription_;
    rclcpp::Subscription<sensor_msgs::msg::Imu>::SharedPtr imu_subscription_;
    rclcpp::TimerBase::SharedPtr timer_;
    sensor_msgs::msg::NavSatFix nav_sat_msg_;
    sensor_msgs::msg::Imu imu_msg_;
};

#endif