#ifndef WIDGET_H
#define WIDGET_H

#include <QOpenGLWidget>

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

private:
    Ui::widget *ui;
    QImage imdisplay;  //This will create QImage which is shown in Qt label
    QTimer* Timer;   // A timer is needed in GUI application
};

#endif // WIDGET_H
