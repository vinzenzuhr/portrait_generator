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
#include "face_detector.h"
#include "img_editor.h"
#include <iostream>
#include <opencv2/highgui.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/imgproc.hpp>
#include "portrait.h"
#include <QApplication>
#include "view_camera.h"
#include "controller_camera.h"

using namespace std;
using namespace cv;

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    controller_camera w(new camera(0), new face_detector);
    /*
    std::cout << "test 1" << std::endl;

    std::unique_ptr<i_camera> webcam(new camera(0));
    std::unique_ptr<i_face_detector> detector(new face_detector);
    Mat img;
    Mat last_img;
    std::shared_ptr<std::vector<cv::Rect>> faces(new std::vector<cv::Rect>);
    while (true) {
        img = webcam->get_current_img();
        if (!img.empty()) {
            last_img = img;
            std::shared_ptr<std::vector<cv::Rect>> new_faces = std::make_shared<std::vector<cv::Rect>>(detector->detect_faces(img));
            if (!new_faces->empty())
                faces = new_faces;
            for_each((*faces).begin(), (*faces).end(), [&img](cv::Rect face) {
                cv::rectangle(img, face.tl(), face.br(), Scalar(255, 0, 255));
                });

            imshow("Frame", img);
        }

        if (cv::waitKey(1)!=-1)
            break;
        waitKey(1);
    }

    std::unique_ptr<i_img_editor> editor(new img_editor(last_img));
    editor->set_bounding_boxes(faces);
    std::vector<portrait> portraits = editor->get_portraits();
    int i = 0;
    for_each(portraits.begin(), portraits.end(), [&i](portrait img) {
        imshow(&"portrait: " [ i], img.get_img());
        i++;
    });
    cv::waitKey();
    */
    return a.exec();
}
