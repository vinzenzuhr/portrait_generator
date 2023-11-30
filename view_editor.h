#ifndef VIEW_EDITOR_H
#define VIEW_EDITOR_H

#include "opencv2/core/types.hpp"
#include "qgraphicsscene.h"
#include <QOpenGLWidget>

namespace Ui {
class view_editor;
}

//Forward declaration to avoid circular inclusions of header files
class controller_editor;

class view_editor : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit view_editor(QWidget *parent = nullptr);

    ~view_editor();

    void register_controller(std::weak_ptr<controller_editor> controller);

    void remove_controller(std::weak_ptr<controller_editor> controller);

    void set_bounding_boxes(std::shared_ptr<std::vector<cv::Rect>> bounding_boxes);

    void set_image(QImage img);

private:
    std::list<std::weak_ptr<controller_editor>> m_controllers;
    std::vector<std::shared_ptr<QGraphicsRectItem>> m_rectangles;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem *m_picture;
    Ui::view_editor *ui;

private slots:
    void click_cancel();

    void click_save();
};

#endif // VIEW_EDITOR_H
