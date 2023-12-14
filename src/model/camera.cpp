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
#include "camera.h"
#include <iostream>

camera::camera(int camera_id) : m_camera_id(camera_id) {
	m_cap.open(m_camera_id);
	if (!m_cap.isOpened()) {
		std::cerr << "ERROR! Unable to open camera";
		throw std::runtime_error("ERROR! Unable to open camera");
	}
		
}

cv::Mat camera::get_current_img() {
	cv::Mat img;
	m_cap.read(img);
	return img;
}
