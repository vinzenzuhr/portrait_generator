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
#ifndef VIEW_CAMERA_H
#define VIEW_CAMERA_H

#include "i_img_observer.h"
#include "img_manager.h"
#include <qgraphicsscene>
#include <QWidget>
#include <memory>

namespace Ui {
class view_camera;
}

//Forward declaration to avoid circular inclusions of header files
class controller_camera;

/**
 * @brief view_camera MVC View of the camera GUI
 */
class view_camera : public QWidget, public i_img_observer
{
    Q_OBJECT

public:
    /**
     * @brief view_camera creates the view
     * @param parent optional QWidget parent
     */
    view_camera(std::shared_ptr<i_img_manager> manager, QWidget *parent = nullptr);

    virtual ~view_camera();

    /**
     * @brief receive_img receive curreng img and displays it
     * @param img img to display
     */
    virtual void receive_img(cv::Mat img) override;

    /**
     * @brief register_controller register an MVC controller
     * @param controller MVC camera controller
     */
    void register_controller(controller_camera* controller);

    /**
     * @brief remove_controller removes an MVC controller
     * @param controller MVC camera controller
     */
    void remove_controller(controller_camera* controller);

private:
    //registered MVC Controllers of the camera GUI
    std::list<controller_camera*> m_controllers;

    //used to show the user current camera img
    QGraphicsPixmapItem *m_picture;
    QGraphicsScene *m_scene;

    //used by QWidget
    Ui::view_camera *ui;

private slots:
    /**
     * @brief click_make_photo calls the controller when button is clicked
     * @throws std::runtime_error thrown if a controller pointer was unexpectedly deleten before.
     */
    void click_make_photo();
};

#endif // VIEW_CAMERA_H
