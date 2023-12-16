#include "img_manager.h"
#include "opencv2/imgproc.hpp"
#include <iostream>

img_manager::img_manager(std::unique_ptr<i_camera> camera, std::unique_ptr<i_face_detector> detector) :
    m_camera(std::move(camera)),
    m_detector(std::move(detector))
{
    const int CREATION_RATE_MS=50;
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(create_new_img()));
    m_timer->start(CREATION_RATE_MS);
}

std::vector<cv::Rect> img_manager::get_last_faces() const{
    return m_last_faces;
}

cv::Mat img_manager::get_last_img() const{
    return m_last_img.clone();
}

void img_manager::register_observer(i_img_observer* observer){
    m_observers.push_back(observer);
}

void img_manager::remove_observer(i_img_observer* observer){
    m_observers.remove(observer);
}

void img_manager::create_new_img(){
    cv::Mat img = m_camera->get_current_img();

    if (!img.empty()) {
        img.copyTo(m_last_img);
        std::vector<cv::Rect> faces = m_detector->detect_faces(img);
        if(!faces.empty()){
            m_last_faces=faces;
            for_each(faces.begin(), faces.end(), [&img](cv::Rect face) {
                cv::rectangle(img, face.tl(), face.br(), cv::Scalar(255, 0, 255));
                });
        }

        std::for_each(m_observers.begin(), m_observers.end(),[img](i_img_observer* observer){
            if (observer != nullptr)
                observer->receive_img(img);
            else{
                std::cerr << "Nullptr ERROR!";
                throw std::runtime_error("Nullptr ERROR!");
            }
        });
    }
}
