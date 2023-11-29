#include "controller_editor.h"

controller_editor::controller_editor(std::shared_ptr<i_img_editor> editor, std::vector<cv::Rect> faces, cv::Mat img, std::shared_ptr<view_editor> view) :
    m_editor(editor),
    m_faces(faces),
    m_img(img),
    m_view(view)
{
    m_view->show();
}
