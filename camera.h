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
#pragma 
#include "i_camera.h" 
#include <opencv2/videoio.hpp>

 /**
 * Grabs a camera and retrieves pictures from it.
 */
class camera : public i_camera
{
public: 
	/**
	* Grabs a camera
	* 
	* @param camera_id id of the camera device to open. To open default camera using default backend just pass 0.
	* 
	* @throws std::runtime_error thrown if it couldn't open the camera.
	* 
	* @exceptsafe strong exception guarantee.
	*/
	explicit camera(int camera_id = 0);

	virtual ~camera() {};

	/**
	* @copydoc i_camera::get_current_img()
	*/
	virtual cv::Mat get_current_img() override;

private: 
	// camera_id of grabbed camera
	int m_camera_id;

	// grabbed camera object
	cv::VideoCapture m_cap;

};

