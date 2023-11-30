#ifndef CONTROLLER_EDITOR_H
#define CONTROLLER_EDITOR_H

#include "i_img_editor.h"
#include "view_editor.h"

class controller_editor
{
public:
    controller_editor(std::shared_ptr<i_img_editor> editor, std::vector<cv::Rect> faces, cv::Mat img, std::shared_ptr<view_editor> view);

    void click_save(std::vector<cv::Rect> faces);

private:
    std::shared_ptr<i_img_editor> m_editor;
    std::vector<cv::Rect> m_faces;
    cv::Mat m_img;
    std::shared_ptr<view_editor> m_view;
};

#endif // CONTROLLER_EDITOR_H
