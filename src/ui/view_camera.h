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
class view_camera : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief view_camera creates the view
     * @param parent optional QWidget parent
     */
    view_camera(QWidget *parent = nullptr);
    //view_camera(std::shared_ptr<controller_camera> controller, QWidget *parent = nullptr);

    ~view_camera();

    /**
     * @brief register_controller register an MVC controller
     * @param controller MVC camera controller
     */
    void register_controller(std::weak_ptr<controller_camera> controller);

    /**
     * @brief remove_controller removes an MVC controller
     * @param controller MVC camera controller
     */
    void remove_controller(std::weak_ptr<controller_camera> controller);

    /**
     * @brief set_image shows the user the current img
     * @param img camera img
     */
    void set_image(QImage img);

private:
    //registered MVC Controllers of the camera GUI
    std::list<std::weak_ptr<controller_camera>> m_controllers;

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
