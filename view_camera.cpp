#include "controller_camera.h"
#include <iostream>
#include <memory>
#include <QGraphicsItem>
#include "ui_view_camera.h"
#include "view_camera.h"
#include "view_editor.h"


view_camera::view_camera(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::view_camera)
{
    ui->setupUi(this);

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
    std::for_each(m_controllers.begin(), m_controllers.end(),[](std::weak_ptr<controller_camera> controller){
        if (std::shared_ptr<controller_camera> spt = controller.lock())
            spt->click_make_photo();
        else{
            std::cerr << "ERROR! Pointer was already deleted.";
            throw std::runtime_error("ERROR! Pointer was already deleted."); //TODO: kommentieren
        }
    });
}

void view_camera::register_controller(std::weak_ptr<controller_camera> controller){
    m_controllers.push_back(controller);
}


void view_camera::remove_controller(std::weak_ptr<controller_camera> controller){
    m_controllers.remove_if([controller](std::weak_ptr<controller_camera> controller_2){
        std::shared_ptr<controller_camera> shared_controller = controller.lock();
        std::shared_ptr<controller_camera> shared_controller_2 = controller_2.lock();
        if(shared_controller && shared_controller)
            return shared_controller == shared_controller;
        return false;
    });
}


void view_camera::set_image(QImage img) {
    m_picture->setPixmap(QPixmap::fromImage(img));
}
