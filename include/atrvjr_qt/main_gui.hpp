#ifndef MAIN_GUI
#define MAIN_GUI

#include <QPushButton>
#include <QWidget>
#include <QMainWindow>
#include <QApplication>
#include <QCamera>
#include <QCameraViewfinder>
#include <QLabel>
#include <QPixmap>

#include "atrvjr_qt/button_pub.hpp"
#include "atrvjr_qt/camera_sub.hpp"

class ATRVJR_GUI : public QMainWindow {
    //Q_OBJECT
 private:
    void process_click();

    const std::shared_ptr<ButtonPublisher> pubNode;
    const std::shared_ptr<CameraSubscriber> camNode;
    QPushButton* button;
    QLabel* imgLabel;

 public: 
    ATRVJR_GUI(const std::shared_ptr<ButtonPublisher>& initPub, const std::shared_ptr<CameraSubscriber>& initCam);
    ~ATRVJR_GUI();

};

#endif