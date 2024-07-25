#include <iostream>
#include <QApplication>
#include "atrvjr_qt/main_gui.hpp"
#include "atrvjr_qt/camera_sub.hpp"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);
    rclcpp::init(argc, argv);
    rclcpp::executors::MultiThreadedExecutor exec;

    ATRVJR_GUI gui;
    gui.addNode<CameraSubscriber>("Webcam", QRect(0, 0, 640, 480));
    
    gui.addExec(exec);
    while (rclcpp::ok() && gui.isVisible())
    {
        exec.spin_some();
        app.processEvents();
    }
    gui.removeExec(exec);

    QApplication::quit();
    rclcpp::shutdown();
}