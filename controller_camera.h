#ifndef CONTROLLER_CAMERA_H
#define CONTROLLER_CAMERA_H

#include "i_camera.h"
#include "i_face_detector.h"
#include <memory>
#include "view_camera.h"
#include <QLabel>

class controller_camera : public QOpenGLWidget
{
public:
    controller_camera(std::shared_ptr<i_camera> camera, std::shared_ptr<i_face_detector> detector, std::shared_ptr<view_camera> view);

    ~controller_camera();

public slots:
    void draw_on_image();

private:
    std::shared_ptr<i_camera> m_camera;
    std::shared_ptr<i_face_detector> m_face_detector;
    QTimer *m_timer;
    std::shared_ptr<view_camera> m_view;


};

#endif // CONTROLLER_CAMERA_H
