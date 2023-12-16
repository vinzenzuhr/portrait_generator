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
#include <memory>
#include <QTimer>
#include "view_camera.h"

/**
 * @brief controller_camera MVC Controller of the camera GUI
 */
class controller_camera
{
public:
    /**
     * @brief controller_camera Creates the controller
     * @param manager manager of the images
     * @param view MVC View of the camera GUI
     */
    controller_camera(std::shared_ptr<i_img_manager> manager, std::shared_ptr<view_camera> view);

    /**
     * @brief click_make_photo when the button is clicked it makes a photo
     */
    void click_make_photo();

private:
    //All editor GUI controllers
    std::list<std::unique_ptr<controller_editor>> m_controller_editors;

    std::shared_ptr<i_img_manager> m_img_manager;

    //MVC View of the camera GUI
    std::shared_ptr<view_camera> m_view;
};

#endif // CONTROLLER_CAMERA_H
