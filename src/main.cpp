#include <iostream>
#include <QObject>
#include <QQuickItem>
#include "atrvjr_qt/button_pub.hpp"
#include "atrvjr_qt/main_gui.hpp"

int main(int argc, char* argv[]){

    QApplication app(argc, argv);
    rclcpp::init(argc, argv);
    
    auto node = std::make_shared<ButtonPublisher>();
    auto gui = std::make_shared<ATRVJR_GUI>(node);
    
    app.processEvents();

    rclcpp::executors::MultiThreadedExecutor exec;
    exec.add_node(node);
    while (rclcpp::ok())
    {
        exec.spin_some();
        app.processEvents();
        if (!(gui->isClosed())) {
            std::cout << "User Closed Window, Shutting Down..." << std::endl;
            break;
        }
    }
    QApplication::quit();
    exec.remove_node(node);
    rclcpp::shutdown();
    return 0;
}