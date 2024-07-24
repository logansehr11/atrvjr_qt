#include <iostream>
#include <QObject>
#include <QQuickItem>
#include "atrvjr_qt/button_pub.hpp"
#include "atrvjr_qt/main_gui.hpp"
#include "atrvjr_qt/camera_sub.hpp"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<ButtonPublisher>();
    auto cam_node = std::make_shared<CameraSubscriber>();
    auto gui = std::make_shared<ATRVJR_GUI>(node, cam_node);
    
    app.processEvents();

    rclcpp::executors::MultiThreadedExecutor exec;
    exec.add_node(node);
    exec.add_node(cam_node);
    while (rclcpp::ok() && gui->isVisible())
    {
        exec.spin_some();
        app.processEvents();
    }
    QApplication::quit();
    exec.remove_node(node);
    exec.remove_node(cam_node);
    rclcpp::shutdown();
    return 0;
}