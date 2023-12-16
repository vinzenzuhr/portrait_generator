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
#ifndef CONTROLLER_CAMERA_H
#define CONTROLLER_CAMERA_H

#include "controller_editor.h"
#include "i_camera.h"
#include "i_face_detector.h"
#include <memory>
#include <QTimer>
#include "view_camera.h"

/**
 * @brief controller_camera MVC Controller of the camera GUI
 */
class controller_camera : public QObject
{

    Q_OBJECT

public:
    /**
     * @brief controller_camera Creates the controller
     * @param camera model of the camera
     * @param detector model of the detector
     * @param view MVC View of the camera GUI
     */
    controller_camera(std::unique_ptr<i_camera> camera, std::unique_ptr<i_face_detector> detector, std::shared_ptr<view_camera> view);

public slots:
    /**
     * @brief click_make_photo when the button is clicked it makes a photo
     */
    void click_make_photo();

private:
    //All editor GUI controllers
    std::list<std::shared_ptr<controller_editor>> m_controller_editors;

    //the camera model
    std::unique_ptr<i_camera> m_camera;

    //the face detector model
    std::unique_ptr<i_face_detector> m_face_detector;

    //timer which updates the GUI and shows the current camera img
    QTimer *m_timer;

    //MVC View of the camera GUI
    std::shared_ptr<view_camera> m_view;

private slots:
    /**
     * @brief draw_on_image sets the image in the MVC View
     */
    void draw_on_image();

};

#endif // CONTROLLER_CAMERA_H
