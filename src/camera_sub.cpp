#include "atrvjr_qt/camera_sub.hpp"

CameraSubscriber::CameraSubscriber() : Node("Camera_Node"){
    subscriber = this->create_subscription<sensor_msgs::msg::Image>("image_raw/compressed", 10, std::bind(&CameraSubscriber::topic_callback, this, std::placeholders::_1));
}

void CameraSubscriber::topic_callback(const sensor_msgs::msg::Image::SharedPtr msg){
    std::cout << "Testing Camera Callback" << std::endl;
}