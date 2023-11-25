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
#include "i_face_detector.h"
#include <opencv2/objdetect.hpp>

/**
* Detect faces in pictures.
*/
class face_detector : public i_face_detector
{
public:
	/**
	* Initializes face detector.
	* 
	* @throws std::runtime_error thrown if the detector couldn't be initialized.
	* 
	* @exceptsafe strong exception guarantee.
	*/
	face_detector();

	virtual ~face_detector() {};

	/**
	* @copydoc i_face_detector::detect_faces(cv::Mat img)
	*/
	virtual std::vector<cv::Rect> detect_faces(cv::Mat img) override;

private:
	// Face classifier
	cv::CascadeClassifier m_face_clf;
};

