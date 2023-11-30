#include <algorithm>
#include "controller_editor.h"
#include <iostream>
#include "view_editor.h"
#include "qgraphicsitem.h"
#include "QDir"
#include "ui_view_editor.h"

view_editor::view_editor(QWidget *parent) :
    QOpenGLWidget(parent),
    ui(new Ui::view_editor)
{
    ui->setupUi(this);

    ui->input_path->setText(QDir::currentPath());

    m_scene = new QGraphicsScene(this);
    ui->graphics_view->setScene(m_scene);
    m_picture = m_scene->addPixmap(QPixmap());

    connect(ui->btn_save, SIGNAL(clicked()), this, SLOT(click_save()));
    connect(ui->btn_cancel, SIGNAL(clicked()), this, SLOT(click_cancel()));
}

view_editor::~view_editor()
{
    delete ui;
}


void view_editor::click_cancel(){
    this->close();
}

void view_editor::click_save(){
    std::vector<cv::Rect> faces;
    for(int i=0; i<m_rectangles.size();i++){
        faces.push_back(cv::Rect(
                            //x,y origin position plus user displacement
                            m_rectangles[i]->rect().x()+m_rectangles[i]->x(),
                            m_rectangles[i]->rect().y()+m_rectangles[i]->y(),
                            m_rectangles[i]->rect().width(),
                            m_rectangles[i]->rect().height()
                            ));
    }

    std::for_each(m_controllers.begin(), m_controllers.end(),[faces](std::weak_ptr<controller_editor> controller){
        if (std::shared_ptr<controller_editor> spt = controller.lock()){
            spt->click_save(faces);
        }
        else{
            std::cerr << "ERROR! Pointer was already deleted.";
            throw std::runtime_error("ERROR! Pointer was already deleted."); //TODO: kommentieren
        }
    });
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

void view_editor::set_bounding_boxes(std::shared_ptr<std::vector<cv::Rect>> bounding_boxes) { //TODO: In der View beim Verschieben neue bounding boxes setzen
    std::for_each(m_rectangles.begin(), m_rectangles.end(), [this](std::shared_ptr<QGraphicsRectItem> &rect){
        m_scene->removeItem(rect.get());
    });

    m_rectangles.clear();

    std::for_each(bounding_boxes->begin(),bounding_boxes->end(), [&](cv::Rect bounding_box){
        double factor_width=1.2; //TODO: ist dies eine gute Idee hier zu machen?
        double factor_height=1.5;
        double x_offset=bounding_box.width*(factor_width-1)/2;
        double y_offset=bounding_box.height*(factor_height-1)/2;
        std::shared_ptr<QGraphicsRectItem> rect(m_scene->addRect(
                                                    std::max(0.0,bounding_box.x-x_offset),
                                                    std::max(0.0,bounding_box.y-y_offset),
                                                    bounding_box.width*factor_width,
                                                    bounding_box.height*factor_height,
                                                    QPen(Qt::blue)));
        rect->setFlag(QGraphicsItem::ItemIsMovable);
        m_rectangles.push_back(rect);
    });
}

void view_editor::set_image(QImage img) {
    m_picture->setPixmap(QPixmap::fromImage(img));
}
