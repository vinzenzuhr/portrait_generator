#include "controller_camera.h"
#include "view_camera.h"
#include <QGraphicsItem>
#include <QTimer>
#include "ui_view_camera.h"



view_camera::view_camera(controller_camera *controller, QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::view_camera),
    m_controller(controller)
{
    ui->setupUi(this);

    //TODO: Testen ob mit shared ptr ich kein Fehler bekomme
    auto scene = new QGraphicsScene(this);
    ui->graphics_view->setScene(scene);
    m_picture = scene->addPixmap(QPixmap());

    int GUI_RATE_MS=50;
    auto timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(draw_on_image()));
    timer->start(GUI_RATE_MS);
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
