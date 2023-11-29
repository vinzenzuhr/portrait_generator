#ifndef VIEW_CAMERA_H
#define VIEW_CAMERA_H

#include <qgraphicsscene>
#include <QOpenGLWidget>
#include <memory>

namespace Ui {
class view_camera;
}

//Forward declaration to avoid circular inclusions of header files
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
    void click_make_photo();

private:
    std::list<std::weak_ptr<controller_camera>> m_controllers;
    QGraphicsScene *m_scene;
    QGraphicsPixmapItem *m_picture;
    Ui::view_camera *ui;
};

#endif // VIEW_CAMERA_H
