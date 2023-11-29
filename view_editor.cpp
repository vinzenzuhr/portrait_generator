#include "view_editor.h"
#include "qgraphicsitem.h"
#include "ui_view_editor.h"

view_editor::view_editor(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::view_editor)
{
    ui->setupUi(this);

    m_scene = new QGraphicsScene(this);
    ui->graphics_view->setScene(m_scene);
    m_picture = m_scene->addPixmap(QPixmap());
}

view_editor::~view_editor()
{
    delete ui;
}

void view_editor::register_controller(std::weak_ptr<controller_editor> controller){
    m_controllers.push_back(controller);
}


void view_editor::remove_controller(std::weak_ptr<controller_editor> controller){
    m_controllers.remove_if([controller](std::weak_ptr<controller_editor> controller_2){
        std::shared_ptr<controller_editor> shared_controller = controller.lock();
        std::shared_ptr<controller_editor> shared_controller_2 = controller_2.lock();
        if(shared_controller && shared_controller)
            return shared_controller == shared_controller;
        return false;
    });
}


void view_editor::set_image(QImage img) {
    m_picture->setPixmap(QPixmap::fromImage(img));
}
