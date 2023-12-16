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
#include <iostream>
#include "portrait.h"

portrait::portrait(cv::Mat img) : m_img(img){
	if (m_img.empty()) {
		std::cerr << "ERROR! Image is valid.";
		throw std::runtime_error("ERROR! Image is valid.");
	}
	m_create_date = std::chrono::system_clock::now();
}

void portrait::check_invariants() const {
	assert(m_img.empty());
}

cv::Mat portrait::get_img() const {
	return m_img;
}
