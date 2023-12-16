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
#include <iostream>
#include <memory>
#include <QGraphicsItem>
#include "ui_view_camera.h"
#include "view_camera.h"


view_camera::view_camera(std::shared_ptr<i_img_manager> manager, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::view_camera)
{
    ui->setupUi(this);

    manager->register_observer(this);

    m_scene = new QGraphicsScene(this);
    ui->graphics_view->setScene(m_scene);
    m_picture = m_scene->addPixmap(QPixmap());

    connect(ui->btn_make_photo, SIGNAL(clicked()), this, SLOT(click_make_photo()));
}

view_camera::~view_camera()
{
    delete ui;
}

void view_camera::click_make_photo() {
    std::for_each(m_controllers.begin(), m_controllers.end(),[this](controller_camera* controller){
        if (controller != nullptr)
            controller->click_make_photo();
        else{
            m_controllers.remove(controller);
        }
    });
}

void view_camera::receive_img(cv::Mat img){
    QImage imdisplay((uchar*)img.data, img.cols, img.rows, img.step, QImage::Format_BGR888);
    m_picture->setPixmap(QPixmap::fromImage(imdisplay));
}

void view_camera::register_controller(controller_camera* controller){
    if (controller == nullptr){
        std::cerr << "Nullptr ERROR!";
        throw std::runtime_error("Nullptr ERROR!");
    }
    m_controllers.push_back(controller);
}


void view_camera::remove_controller(controller_camera* controller){
    m_controllers.remove(controller);
}
