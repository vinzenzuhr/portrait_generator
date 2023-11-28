#include "controller_camera.h"
#include "view_camera.h"
#include <QGraphicsItem>
#include <QTimer>
#include "ui_view_camera.h"



view_camera::view_camera(std::shared_ptr<controller_camera> controller, QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::view_camera),
    m_controller(controller)
{
    ui->setupUi(this);



    //TODO: Testen ob mit shared ptr ich kein Fehler bekomme
    m_scene.reset(new QGraphicsScene(this));
    ui->graphics_view->setScene(m_scene.get());
    m_picture.reset(m_scene->addPixmap(QPixmap()));



    int GUI_RATE_MS=50;
    m_timer.reset(new QTimer(this));
    connect(m_timer.get(), SIGNAL(timeout()), this, SLOT(draw_on_image()));
    m_timer->start(GUI_RATE_MS);
}

view_camera::~view_camera()
{
    delete ui;
}

void view_camera::draw_on_image() {
    m_controller->draw_on_image();
}

void view_camera::set_image(QImage img) {
    m_picture->setPixmap(QPixmap::fromImage(img));

//ui->label->setPixmap();
}
