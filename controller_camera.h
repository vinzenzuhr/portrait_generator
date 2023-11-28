#ifndef CONTROLLER_CAMERA_H
#define CONTROLLER_CAMERA_H

#include "i_camera.h"
#include "i_face_detector.h"
#include <memory>
#include "view_camera.h"

class controller_camera
{
public:
    controller_camera(i_camera *camera, i_face_detector *detector);

    void draw_on_image();

private:
    std::unique_ptr<i_camera> m_camera;
    std::unique_ptr<i_face_detector> m_face_detector;
    view_camera m_view;
};

#endif // CONTROLLER_CAMERA_H
