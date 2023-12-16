#ifndef I_IMG_MANAGER_H
#define I_IMG_MANAGER_H

#include "i_img_observer.h"
#include "opencv2/core/types.hpp"

class i_img_manager
{
public:
    virtual ~i_img_manager(){};

    virtual std::vector<cv::Rect> get_last_faces() const =0;

    virtual cv::Mat get_last_img() const = 0;

    /**
     * @brief register_observer register an observer
     * @param observer observes if a new img is available
     */
    virtual void register_observer(i_img_observer* observer) =0;

    /**
     * @brief remove_observer remove an observer
     * @param observer observer to be removed
     */
    virtual void remove_observer(i_img_observer* observer) =0;
};

#endif // I_IMG_MANAGER_H
