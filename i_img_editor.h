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
#include <opencv2/core/types.hpp>
#include "portrait.h"
#include <vector>


class i_img_editor
{
public:
	virtual ~i_img_editor() {};

	virtual std::shared_ptr<std::vector<cv::Rect>> get_bounding_boxes() =0;

	virtual cv::Mat get_img() =0;

	virtual std::vector<portrait> get_portraits() =0;

	virtual void set_bounding_boxes(std::shared_ptr<std::vector<cv::Rect>> bounding_boxes) =0;
};

