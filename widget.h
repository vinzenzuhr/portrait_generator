#ifndef WIDGET_H
#define WIDGET_H

#include "i_camera.h"
#include <QOpenGLWidget>
#include <QGraphicsScene>

#include <opencv2/imgproc.hpp>

namespace Ui {
class widget;
}

class widget : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit widget(QWidget *parent = nullptr);
    ~widget();

private slots:
    void DisplayImage();
    void clickButton();

private:
    //TODO: überall unique ptr verwenden
    Ui::widget *ui;
    QImage imdisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application
    std::unique_ptr<i_camera> webcam;
    QGraphicsScene *scene;
    QGraphicsPixmapItem * picture;
    cv::Mat img;
    QGraphicsRectItem* newRect;
};

#endif // WIDGET_H
