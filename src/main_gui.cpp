#include "atrvjr_qt/main_gui.hpp"

#include <QPushButton>
#include <QCamera>
#include <QCameraViewfinder>

ATRVJR_GUI::ATRVJR_GUI(const std::shared_ptr<ButtonPublisher>& initPubNode) : QMainWindow(nullptr), pubNode(initPubNode){
    window.resize(800, 664);
    window.setWindowTitle(QApplication::translate(
        "JuniorWindow", "ATRV-JR"));
    button = new QPushButton(QApplication::translate(
        "JuniorWindow", "Publish Message"), &window);
    button->resize(256, 64);
    button->move((window.size().width() - button->size().width())/2, 600);
    connect(button, &QPushButton::clicked, this, &ATRVJR_GUI::process_click);
    
    vf = new QCameraViewfinder(&window);
    vf->resize(800, 600);
    vf->move((window.size().width() - vf->size().width())/2, 0);

    vf->show();
    camera.setViewfinder(*(&vf));
    camera.start();
    button->show();
    window.show();
}

ATRVJR_GUI::~ATRVJR_GUI() {}

void ATRVJR_GUI::process_click(){
    pubNode->publishMsg("This is a message from Junior's Interface!");
}