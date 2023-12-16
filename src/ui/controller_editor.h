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
#ifndef CONTROLLER_EDITOR_H
#define CONTROLLER_EDITOR_H

#include "i_img_editor.h"
#include "view_editor.h"

/**
 * @brief controller_editor MVC Controller of the camera GUI
 */
class controller_editor
{
public:
    /**
     * @brief controller_editor creates the controller
     * @param editor model of the editor
     * @param faces detected faces in the image
     * @param img image which was taken by the user
     * @param view MVC View of the editor GUI
     */
    controller_editor(std::unique_ptr<i_img_editor> editor, std::vector<cv::Rect> faces, cv::Mat img, std::shared_ptr<view_editor> view);

public slots:
    /**
     * @brief click_save when the button is clicked it saves the portraits
     * @param bounding_boxes bounding boxes inside the image of the portraits to be saved
     * @param path path to save the portraits
     */
    void click_save(std::vector<cv::Rect> bounding_boxes, std::string path);

private:
    //model of the editor
    std::unique_ptr<i_img_editor> m_editor;

    //image which was taken by the user
    cv::Mat m_img;

    //MVC View of the editor GUI
    std::shared_ptr<view_editor> m_view;
};

#endif // CONTROLLER_EDITOR_H
