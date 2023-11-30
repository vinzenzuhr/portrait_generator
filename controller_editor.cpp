#include "controller_editor.h"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>

controller_editor::controller_editor(std::shared_ptr<i_img_editor> editor, std::vector<cv::Rect> faces, cv::Mat img, std::shared_ptr<view_editor> view) :
    m_editor(editor),
    m_faces(faces),
    m_img(img),
    m_view(view)
{
    m_view->show(); //TODO: evt. ans Ende

    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888); //TODO: in eigene Funktion
    m_view->set_image(imdisplay);
    m_view->set_bounding_boxes(std::make_shared<std::vector<cv::Rect>>(faces));

    m_editor->set_bounding_boxes(std::make_shared<std::vector<cv::Rect>>(faces)); //TODO: Überlegen ob ohne shared pointer

}

void controller_editor::click_save(std::vector<cv::Rect> faces) {
    if(faces.size()<2){
        cv::imwrite("portrait.jpg", m_img(faces[0])); //TODO: Include path
    } else {
        for(int i=0; i<faces.size(); i++)
            cv::imwrite("portrait_" + std::to_string(i+1) + ".jpg", m_img(faces[i])); //TODO: Include path
    }
}
