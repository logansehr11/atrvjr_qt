#include "atrvjr_qt/main_gui.hpp"

ATRVJR_GUI::ATRVJR_GUI(const std::shared_ptr<ButtonPublisher>& initPub, const std::shared_ptr<CameraSubscriber>& initCam) : QMainWindow(nullptr), pubNode(initPub), camNode(initCam){
    // Window Setup
    this->resize(800, 664);
    this->setWindowTitle(QApplication::translate(
        "JuniorWindow", "ATRV-JR"));

    // Publish Button Setup
    button = new QPushButton(QApplication::translate(
        "JuniorWindow", "Publish Message"), this);
    button->resize(256, 64);
    button->move((this->size().width() - button->size().width())/2, 600);
    connect(button, 
        &QPushButton::clicked, 
        this, 
        &ATRVJR_GUI::process_click
    );

    // Camera Label Setup
    imgLabel = new QLabel(this);
    camNode->setLabel(imgLabel);
    imgLabel->resize(640, 480);
    imgLabel->move((this->size().width() - imgLabel->size().width())/2, 0);

    // Interface View
    button->show();
    imgLabel->show();
    this->show();
}

ATRVJR_GUI::~ATRVJR_GUI(){
    delete button;
    delete imgLabel;
}

void ATRVJR_GUI::process_click(){
    pubNode->publishMsg("This is a message from Junior's Interface!");
}