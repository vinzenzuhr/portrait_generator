/*
 * This file is part of portrait_generator.
 *
 * Developed for the class "C++ Programming II" at University Berne.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Regarding the GNU General Public License have a look at <https://www.gnu.org/licenses/>.
 */
#include "controller_camera.h"
#include "controller_editor.h"
#include "img_editor.h"
#include "view_editor.h"
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

    if (!img.empty()) {
        std::shared_ptr<std::vector<cv::Rect>> faces = std::make_shared<std::vector<cv::Rect>>(m_face_detector->detect_faces(img));
        for_each((*faces).begin(), (*faces).end(), [&img](cv::Rect face) {
            cv::rectangle(img, face.tl(), face.br(), cv::Scalar(255, 0, 255));
            });
    }

    cv::cvtColor(img,img,cv::COLOR_BGR2RGB);
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_RGB888);
    m_view->set_image(imdisplay); //

}

void controller_camera::click_make_photo() {
    cv::Mat img;
    std::vector<cv::Rect> faces;

    while(faces.empty())
    {
        img = m_camera->get_current_img();
        cv::cvtColor(img,img,cv::COLOR_BGR2RGB);

        if (!img.empty()) {
            faces = std::vector<cv::Rect>(m_face_detector->detect_faces(img));
        }
    }

    std::shared_ptr<i_img_editor> editor (new img_editor(img));
    std::shared_ptr<view_editor> view (new view_editor);
    std::shared_ptr<controller_editor> controller(new controller_editor(editor, faces, img, view));
    m_controller_editors.push_back(controller); // TODO: wird nie aufgeräumt
    view->register_controller(std::weak_ptr<controller_editor> (controller));
}
