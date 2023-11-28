#include "controller_camera.h"
#include <iostream>
#include <opencv2/imgproc.hpp>

controller_camera::controller_camera(i_camera *camera, i_face_detector *detector) :
    m_camera(camera),
    m_face_detector(detector),
    m_view( view_camera(this) )
{
    m_view.show();
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

    m_view.set_image(imdisplay);

     //display the image




}
