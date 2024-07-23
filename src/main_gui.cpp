#include "atrvjr_qt/main_gui.hpp"

ATRVJR_GUI::ATRVJR_GUI(const std::shared_ptr<ButtonPublisher>& initPubNode) : QMainWindow(nullptr), pubNode(initPubNode){
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
    
    // Viewfinder Setup
    vf = new QCameraViewfinder(this);
    vf->resize(800, 600);
    vf->move((this->size().width() - vf->size().width())/2, 0);

    // Camera Setup 
    camera = new QCamera();

    // Display Instructions
    vf->show();
    camera->setViewfinder(vf);
    camera->start();
    button->show();
    this->show();
}

ATRVJR_GUI::~ATRVJR_GUI(){
    delete vf;
    delete button;
    delete camera;
}

void ATRVJR_GUI::process_click(){
    pubNode->publishMsg("This is a message from Junior's Interface!");
}