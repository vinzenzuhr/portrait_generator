#include "controller_camera.h"
#include <opencv2/imgproc.hpp>

controller_camera::controller_camera(std::shared_ptr<i_camera> camera, std::shared_ptr<i_face_detector> detector, std::shared_ptr<view_camera> view) :
    m_camera(camera),
    m_face_detector(detector),
    m_view(view)
{
    m_view->show();

    int GUI_RATE_MS=50;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(draw_on_image()));
    m_timer->start(GUI_RATE_MS);

}

void controller_camera::draw_on_image() {

    //TODO: multi threading einführen
    cv::Mat img = m_camera->get_current_img();
    /*
    if (!img.empty()) {
        std::shared_ptr<std::vector<cv::Rect>> faces = std::make_shared<std::vector<cv::Rect>>(m_face_detector->detect_faces(img));
        for_each((*faces).begin(), (*faces).end(), [&img](cv::Rect face) {
            cv::rectangle(img, face.tl(), face.br(), cv::Scalar(255, 0, 255));
            });
    }*/








    //img = imread("GOPR0221.JPG");
    //cv::resize(img, img, Size(512, 384), 0, 0, INTER_LINEAR);
    cv::cvtColor(img,img,cv::COLOR_BGR2RGB); //Qt reads in RGB whereas CV in BGR
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888); //Converts the CV image into Qt standard format
    m_view->set_image(imdisplay); //




}
