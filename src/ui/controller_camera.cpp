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

controller_camera::controller_camera(std::shared_ptr<i_img_manager> manager, std::shared_ptr<view_camera> view) :
    m_img_manager(manager),
    m_view(view) //TODO: If a view gets destructed, the corresponding controller should be destructed as well.
{
    m_view->show();
}

void controller_camera::click_make_photo() {
    cv::Mat img(m_img_manager->get_last_img());
    std::vector<cv::Rect> faces(m_img_manager->get_last_faces());

    std::shared_ptr<view_editor> view = std::make_shared<view_editor>();
    std::unique_ptr<controller_editor> controller = std::make_unique<controller_editor>(std::make_unique<img_editor>(img), faces, img, view);
    view->register_controller(controller.get());
    m_controller_editors.push_back(std::move(controller)); // TODO: controller can't remove itself
}
