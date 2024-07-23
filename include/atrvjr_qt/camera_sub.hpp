#ifndef CAMERA_SUB
#define CAMERA_SUB

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"

class CameraSubscriber : public rclcpp::Node {
 private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber;

 public:
    CameraSubscriber();
    void topic_callback(const sensor_msgs::msg::Image::SharedPtr msg);
};

#endif