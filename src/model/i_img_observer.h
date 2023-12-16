#ifndef I_IMG_OBSERVER_H
#define I_IMG_OBSERVER_H


#include "opencv2/core/mat.hpp"
class i_img_observer
{
public:
    virtual ~i_img_observer(){};

    virtual void receive_img(cv::Mat img) =0;
};

#endif // I_IMG_OBSERVER_H
