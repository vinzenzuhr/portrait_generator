#ifndef VIEW_CAMERA_H
#define VIEW_CAMERA_H

#include <qgraphicsscene>
#include <QGraphicsPixmapItem>
#include <QOpenGLWidget>
#include <QTimer>
#include <memory>

namespace Ui {
class view_camera;
}

class controller_camera;

class view_camera : public QOpenGLWidget
{
    Q_OBJECT

public:
    view_camera(QWidget *parent = nullptr);
    //view_camera(std::shared_ptr<controller_camera> controller, QWidget *parent = nullptr);

    ~view_camera();

    void register_controller(std::weak_ptr<controller_camera> controller);

    void remove_controller(std::weak_ptr<controller_camera> controller);

    void set_image(QImage img);

private slots:
    void draw_on_image();

private:
    //std::unique_ptr<Ui::view_camera> ui;
    Ui::view_camera *ui;
    std::list<std::weak_ptr<controller_camera>> controllers;

    QGraphicsScene *m_scene;
    QGraphicsPixmapItem *m_picture;
    QTimer *m_timer;
};

#endif // VIEW_CAMERA_H
