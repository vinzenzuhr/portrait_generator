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
#include "camera.h"
#include "controller_camera.h"
#include "face_detector.h"
#include <QApplication>
#include "view_camera.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::shared_ptr<i_camera> webcam(new camera(0));
    std::shared_ptr<i_face_detector> detector(new face_detector);

    std::shared_ptr<view_camera> view(new view_camera());
    std::shared_ptr<controller_camera> controller(new controller_camera (webcam, detector, view));
    view->register_controller(std::weak_ptr<controller_camera> (controller));

    return a.exec();
}
