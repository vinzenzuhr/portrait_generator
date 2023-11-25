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
#include <opencv2/core/types.hpp>
#include <vector>

 /**
 * Interface to detector, which detects faces in pictures
 */
class i_face_detector
{
public:
	virtual ~i_face_detector() {};

	/**
	* Detects faces of different sizes in the input image.
	* 
	* @param img input image, where objects are detected
	* 
	* @returns the detected objects are returned as a list of rectangles
	*/
	virtual std::vector<cv::Rect> detect_faces(cv::Mat img) =0; 
};