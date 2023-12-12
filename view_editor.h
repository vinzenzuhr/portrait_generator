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
#ifndef VIEW_EDITOR_H
#define VIEW_EDITOR_H

#include "opencv2/core/types.hpp"
#include "qgraphicsscene.h"
#include <QWidget>

namespace Ui {
class view_editor;
}

//Forward declaration to avoid circular inclusions of header files
class controller_editor;

/**
 * @brief view_editor MVC View of the editor GUI
 */
class view_editor : public QWidget
{
    Q_OBJECT

public:
    /**
     * @brief view_editor creates the view
     * @param parent optional QWidget parent
     */
    explicit view_editor(QWidget *parent = nullptr);

    ~view_editor();

    /**
     * @brief register_controller register an MVC controller
     * @param controller MVC editor controller
     */
    void register_controller(std::weak_ptr<controller_editor> controller);

    /**
     * @brief register_controller remove an MVC controller
     * @param controller MVC editor controller
     */
    void remove_controller(std::weak_ptr<controller_editor> controller);

    /**
     * @brief set_bounding_boxes set active bounding boxes and shows them to the user
     * @param bounding_boxes bounding boxes in the image
     */
    void set_bounding_boxes(std::vector<cv::Rect> bounding_boxes);

    /**
     * @brief set_image shows the user the img
     * @param img image which was taken by the user
     */
    void set_image(QImage img);

private:
    //registered MVC Controllers of the editor GUI
    std::list<std::weak_ptr<controller_editor>> m_controllers;

    //bounding boxes inside the image
    std::vector<std::shared_ptr<QGraphicsRectItem>> m_bounding_boxes;

    //used to show the user current camera img
    QGraphicsPixmapItem *m_picture;
    QGraphicsScene *m_scene;

    //used by QWidget
    Ui::view_editor *ui;

private slots:
    /**
     * @brief click_cancel when the button is clicked close the window
     */
    void click_cancel();

    /**
     * @brief click_save when the button is clicked call the controllers
     * @throws std::runtime_error thrown if a controller pointer was unexpectedly deleten before.
     */
    void click_save();
};

#endif // VIEW_EDITOR_H
