/*
 * This file is part of portrait_generator.
 *
 * Developed for the class "C++ Programming II" at University Berne.
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * Regarding the GNU General Public License have a look at <https://www.gnu.org/licenses/>.
 */
#pragma once
#include <opencv2/core/mat.hpp>

 /**
 * Interface to a camera, which retrieves pictures from it.
 */
class i_camera
{
public: 
	virtual ~i_camera() {};

	/**
	* Gets an image from the camera
	* 
	* @returns the video frame is returned here. If no frame has been grabbed the image will be empty (test it with Mat::empty()).
	*/
	virtual cv::Mat get_current_img() = 0;
};