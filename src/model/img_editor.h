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
#include <iostream> //TODO: entfernen
#include <memory>
#include <opencv2/core/mat.hpp>

/**
* @brief img_editor Edits an image
*/
class img_editor : public i_img_editor
{
public:
	/**
    * @brief img_editor Initializes the editor
    * @param img image which will be edited
    * @throws std::runtime_error thrown if image is empty.
	* @exceptsafe strong exception guarantee.
	*/
	explicit img_editor(cv::Mat img);

    virtual ~img_editor() {};

    /**
    * @copydoc i_img_editor::get_bounding_boxes()
    */
    virtual std::vector<cv::Rect> get_bounding_boxes() const override;

    /**
    * @copydoc i_img_editor::get_img()
    */
    virtual cv::Mat get_img() const override;

    /**
    * @copydoc i_img_editor::get_portraits()
    */
    virtual std::vector<portrait> get_portraits() const override;

    /**
    * @copydoc i_img_editor::set_bounding_boxes()
    */
    virtual void set_bounding_boxes(std::vector<cv::Rect> bounding_boxes) override;

private: 
    //bounding boxes to cut out
    std::vector<cv::Rect> m_bounding_boxes;

	// image which is being edited
	cv::Mat m_img;

	/**
    * @brief check_bounding_box Check if bounding boxes are out of bounds
	* @returns false if bounding boxes are out of bounds and true if everything is good. 
	*/
    bool check_bounding_box(std::vector<cv::Rect> bounding_boxes) const;

	/**
    * @brief check_invariants Check the invariants
	*/
    void check_invariants() const;
};

