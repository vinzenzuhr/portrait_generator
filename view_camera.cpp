#include "controller_camera.h"
#include "view_camera.h"
#include <QGraphicsItem>
#include <QTimer>
#include <iostream>
#include "ui_view_camera.h"



view_camera::view_camera(QWidget *parent) :
//view_camera::view_camera(std::shared_ptr<controller_camera> controller, QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::view_camera)
{
    ui->setupUi(this);



    //TODO: Testen ob mit shared ptr ich kein Fehler bekomme
    m_scene = new QGraphicsScene(this);
    ui->graphics_view->setScene(m_scene);
    m_picture = m_scene->addPixmap(QPixmap());


    /*
    int GUI_RATE_MS=50;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(draw_on_image()));
    m_timer->start(GUI_RATE_MS);
    */
}

view_camera::~view_camera()
{
    //if(ui!=nullptr)
    delete ui;
    //ui=nullptr;
    std::cout << "test";
}

void view_camera::draw_on_image() {
    std::for_each(controllers.begin(), controllers.end(),[](std::weak_ptr<controller_camera> controller){
        if (std::shared_ptr<controller_camera> spt = controller.lock())
            spt->draw_on_image();
        else
            std::cout << "gw is expired\n"; //TODO: throw exception
    });
}

void view_camera::register_controller(std::weak_ptr<controller_camera> controller){
    controllers.push_back(controller);
}

/*
void view_camera::remove_controller(std::weak_ptr<controller_camera> controller){
    controllers.remove(controller);
} TODO: Find solutions
*/

void view_camera::set_image(QImage img) {
    m_picture->setPixmap(QPixmap::fromImage(img));
}
