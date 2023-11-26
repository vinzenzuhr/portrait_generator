#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QTimer>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2\core\core.hpp"
#include "camera.h"

using namespace cv;


widget::widget(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);

    webcam.reset(new camera(0));

    Timer = new QTimer(this);
    connect(Timer, SIGNAL(timeout()), this, SLOT(DisplayImage()));
    Timer->start(50); //TODO: variable draus machen
}

widget::~widget()
{
    delete ui;
}

void widget::DisplayImage(){
    img = webcam->get_current_img();
    //img = imread("GOPR0221.JPG");
    cv::resize(img, img, Size(512, 384), 0, 0, INTER_LINEAR);
    cv::cvtColor(img,img,COLOR_BGR2RGB); //Qt reads in RGB whereas CV in BGR
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888); //Converts the CV image into Qt standard format
    ui->display_image->setPixmap(QPixmap::fromImage(imdisplay));//display the image in label that is created earlier
}
