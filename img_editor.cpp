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
#include "img_editor.h"
#include <iostream>

img_editor::img_editor(cv::Mat img) : m_img(img) {
	if (m_img.empty()) {
		std::cerr << "ERROR! Image is valid.";
		throw std::runtime_error("ERROR! Image is valid.");
	}
}

bool img_editor::check_bounding_box(std::vector<cv::Rect> bounding_boxes) {
	bool result = true;
	//TODO: Zugriff auf resource bounding_boxes evt. mutexen
    for_each(bounding_boxes.begin(), bounding_boxes.end(), [&result, this](cv::Rect bounding_box) {
		if (bounding_box.tl().x < 0)
			result = false;
		if (bounding_box.tl().y < 0)
			result = false;
		if (bounding_box.br().x > m_img.cols)
			result = false;
		if (bounding_box.br().y > m_img.rows)
			result = false;
	});
	return result;
}

void img_editor::check_invariants() {
    assert(!m_img.empty());
}

std::vector<cv::Rect> img_editor::get_bounding_boxes() {
	return m_bounding_boxes;
}

cv::Mat img_editor::get_img() {
	return m_img;
}

std::vector<portrait> img_editor::get_portraits() {
    if (!check_bounding_box(m_bounding_boxes)) {
		std::cerr << "ERROR! Bounding boxes are out of bounce.";
		throw std::runtime_error("ERROR! Bounding boxes are out of bounce.");
	}
	std::vector<portrait> portraits; 
    for_each(m_bounding_boxes.begin(), m_bounding_boxes.end(), [this, &portraits](cv::Rect bounding_box) {
		auto croped_img = m_img(bounding_box);  
		portraits.push_back(portrait(croped_img));
	}); 
	return portraits;
}

void img_editor::set_bounding_boxes(std::vector<cv::Rect> bounding_boxes) {
	if (!check_bounding_box(bounding_boxes)) {
		std::cerr << "ERROR! Bounding boxes are out of bounce.";
		throw std::runtime_error("ERROR! Bounding boxes are out of bounce.");
	}
	m_bounding_boxes = bounding_boxes;
	check_invariants();
}


 
