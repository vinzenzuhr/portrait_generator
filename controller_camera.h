#ifndef CONTROLLER_CAMERA_H
#define CONTROLLER_CAMERA_H

#include "controller_editor.h"
#include "i_camera.h"
#include "i_face_detector.h"
#include <memory>
#include <QTimer>
#include "view_camera.h"

class controller_camera : public QObject
{

    Q_OBJECT

public:
    controller_camera(std::shared_ptr<i_camera> camera, std::shared_ptr<i_face_detector> detector, std::shared_ptr<view_camera> view);

public slots:
    void draw_on_image(); //TODO: move to private
    void click_make_photo();

private:
    std::list<std::shared_ptr<controller_editor>> m_controller_editors;
    std::shared_ptr<i_camera> m_camera;
    std::shared_ptr<i_face_detector> m_face_detector;
    QTimer *m_timer;
    std::shared_ptr<view_camera> m_view;


};

#endif // CONTROLLER_CAMERA_H
