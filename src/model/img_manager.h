#ifndef IMG_MANAGER_H
#define IMG_MANAGER_H

#include "i_camera.h"
#include "i_face_detector.h"
#include "i_img_manager.h"
#include <QObject>
#include <QTimer>

class img_manager : public QObject, public i_img_manager
{

    Q_OBJECT

public:
    img_manager(std::unique_ptr<i_camera> camera, std::unique_ptr<i_face_detector> detector);

    virtual ~img_manager(){};

    virtual std::vector<cv::Rect> get_last_faces() const override;

    virtual cv::Mat get_last_img() const override;

    virtual void register_observer(i_img_observer* observer) override;

    virtual void remove_observer(i_img_observer* observer) override;

private:
    std::unique_ptr<i_camera> m_camera;

    std::unique_ptr<i_face_detector> m_detector;

    std::vector<cv::Rect> m_last_faces;

    cv::Mat m_last_img;

    std::list<i_img_observer*> m_observers;

    QTimer *m_timer;

private slots:
    void create_new_img();
};

#endif // IMG_MANAGER_H
