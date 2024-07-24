#include "atrvjr_qt/camera_sub.hpp"

CameraSubscriber::CameraSubscriber() : Node("Camera_Node"){
    subscriber = this->create_subscription<sensor_msgs::msg::Image>("image_raw", 10, std::bind(&CameraSubscriber::image_callback, this, std::placeholders::_1));
}

void CameraSubscriber::image_callback(const sensor_msgs::msg::Image::SharedPtr msg){
    label->setPixmap(QPixmap::fromImage(ros_image_to_qimage::Convert(*msg)));
}