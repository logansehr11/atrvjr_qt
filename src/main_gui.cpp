#include "atrvjr_qt/main_gui.hpp"

#include <QPushButton>

MainGUI::MainGUI(const std::shared_ptr<InterfaceNode>& initPubNode) : QMainWindow(nullptr), pubNode(initPubNode) {
    window.resize(800, 664);
    window.setWindowTitle(QApplication::translate(
        "JuniorWindow", "Junior Window"));
    button = new QPushButton(QApplication::translate(
        "JuniorWindow", "Button"), &window);
    button->resize(256, 64);
    button->move((window.size().width() - button->size().width())/2, 600);
    connect(button, &QPushButton::clicked, this, &MainGUI::process_click);
    button->show();
    window.show();

    /*
    WORK IN PROGRESS CAMERA 
    QCamera camera;
    QCameraViewfinder vf(&window);
    vf.resize(800, 600);
    vf.move((window.size().width() - vf.size().width())/2, 0);

    vf.show();
    camera.setViewfinder(&vf);
    camera.start();
    */
}

MainGUI::~MainGUI() {}

void MainGUI::process_click() {
    pubNode->publishMsg("This is a message from Junior's Interface!");
}