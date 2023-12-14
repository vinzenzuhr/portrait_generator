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
#include <chrono>

/**
* @brief portrait portrait which helds an image and additional informations
*/
class portrait
{
public:
	/**
    * @brief portrait Initializes a portrait
    * @param img the image of the person
    * @throws std::runtime_error thrown if image is empty.
	* @exceptsafe strong exception guarantee.
	*/
	explicit portrait(cv::Mat img);

	/**
    * @brief check_invariants Check invariants
	*/
	void check_invariants(); 

	/**
    * @brief get_img get image
	* @returns image of the person
	*/
	cv::Mat get_img();

private:
	//creation date of the portrait object
	std::chrono::time_point<std::chrono::system_clock> m_create_date;

	//image of the person
	cv::Mat m_img; 
};

