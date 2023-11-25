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
#include "i_img_editor.h"
#include <memory>
#include <opencv2/core/mat.hpp>

/**
* Edits an image 
*/
class img_editor : public i_img_editor
{
public:
	/**
	* Initializes the editor
	* 
	* @param img image which will be edited
	* 
	* @throws std::runtime_error thrown if image is empty.
	* 
	* @exceptsafe strong exception guarantee.
	*/
	explicit img_editor(cv::Mat img);

	virtual ~img_editor() {};

	/**
	* Get bounding boxes
	* 
	* @returns shared pointer to bounding boxes
	*/
	virtual std::shared_ptr<std::vector<cv::Rect>> get_bounding_boxes() override;

	/**
	* Get image
	* 
	* @returns image which is edited
	*/
	virtual cv::Mat get_img() override;

	/**
	* Get portraits from image image based on bounding boxes
	* 
	* @throws std::runtime_error thrown if bounding boxes are out of bounds.
	* 
	* @exceptsafe strong exception guarantee.
	*/
	virtual std::vector<portrait> get_portraits() override;

	/**
	* Set bounding boxes
	* 
	* @param bounding boxes which have to be inside the image
	*
	* @throws std::runtime_error thrown if bounding boxes are out of bounds.
	*
	* @exceptsafe strong exception guarantee.
	*/
	virtual void set_bounding_boxes(std::shared_ptr<std::vector<cv::Rect>> bounding_boxes) override;

private: 
	std::shared_ptr <std::vector<cv::Rect>> m_bounding_boxes;

	// image which is being edited
	cv::Mat m_img;

	/**
	* Check if bounding boxes are out of bounds
	* 
	* @returns false if bounding boxes are out of bounds and true if everything is good. 
	*/
	bool check_bounding_box(std::shared_ptr <std::vector<cv::Rect>> bounding_boxes = nullptr);

	/**
	* Check the invariants
	*/
	void check_invariants();
};

