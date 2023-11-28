#include "widget.h"
#include "ui_widget.h"
#include <iostream>
#include <QTimer>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2\core\core.hpp"
#include "camera.h"
#include "QGraphicsItem"

using namespace cv;


widget::widget(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::widget)
{
    ui->setupUi(this);

    webcam.reset(new camera(0));
    scene = new QGraphicsScene(this); //TODO: uniqueptr
    ui->graphicsView->setScene(scene);
    picture = scene->addPixmap(QPixmap());
    newRect = scene->addRect(10,10,100,100,QPen(Qt::blue));
    newRect->setFlag(QGraphicsItem::ItemIsMovable);

    connect(ui->photo_button, SIGNAL(clicked()), this, SLOT(clickButton()));

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
    //cv::resize(img, img, Size(512, 384), 0, 0, INTER_LINEAR);
    cv::cvtColor(img,img,COLOR_BGR2RGB); //Qt reads in RGB whereas CV in BGR
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888); //Converts the CV image into Qt standard format
    picture->setPixmap(QPixmap::fromImage(imdisplay)); //display the image
    //ui->label->setPixmap();
}


void widget::clickButton(){
    //widget* wdg = new widget;
    //wdg->show();
    //hide();
    //auto boundingBox = newRect->boundingRect();
    cv::Rect roi(newRect->pos().x(),newRect->pos().y(),100,100);
    cv::imshow("img", img(roi));

}
