#ifndef CAMERA_SUB
#define CAMERA_SUB

#include "rclcpp/rclcpp.hpp"
#include "sensor_msgs/msg/image.hpp"
#include <QImage>
#include <QLabel>
#include "ros_image_to_qimage/ros_image_to_qimage.hpp"

class CameraSubscriber : public rclcpp::Node {
 private:
    rclcpp::Subscription<sensor_msgs::msg::Image>::SharedPtr subscriber;
    QImage img;
    QLabel* label;

 public:
    CameraSubscriber();
    void image_callback(const sensor_msgs::msg::Image::SharedPtr msg);
    void setLabel(QLabel* newLabel) { label = newLabel; }
};

#endif