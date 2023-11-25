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
#include "face_detector.h"
#include <iostream>

face_detector::face_detector() {
	m_face_clf.load("haarcascade_frontalface_default.xml");
	if (m_face_clf.empty()) {
		std::cerr << "ERROR! Couldn't load detector.";
		throw std::runtime_error("ERROR! Couldn't load detector.");
	}
}

std::vector<cv::Rect> face_detector::detect_faces(cv::Mat img) { 
	std::vector<cv::Rect> faces;
	double scale_factor = 1.1;
	int min_neighbors = 10;
	m_face_clf.detectMultiScale(img, faces, scale_factor, min_neighbors);
	return faces;
}