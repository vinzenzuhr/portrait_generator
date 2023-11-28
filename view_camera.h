#ifndef VIEW_CAMERA_H
#define VIEW_CAMERA_H

#include "qgraphicsscene.h"
#include <QOpenGLWidget>
#include <memory>

namespace Ui {
class view_camera;
}

class controller_camera;

class view_camera : public QOpenGLWidget
{
    Q_OBJECT

public:
    view_camera(std::shared_ptr<controller_camera> controller, QWidget *parent = nullptr);

    ~view_camera();

    void set_image(QImage img);

private slots:
    void draw_on_image();

private:
    Ui::view_camera *ui;
    std::shared_ptr<controller_camera> m_controller;
    //std::unique_ptr<QGraphicsPixmapItem> m_picture;
    std::unique_ptr<QGraphicsScene> m_scene;
    std::unique_ptr<QGraphicsPixmapItem> m_picture;
    std::unique_ptr<QTimer> m_timer;
};

#endif // VIEW_CAMERA_H
