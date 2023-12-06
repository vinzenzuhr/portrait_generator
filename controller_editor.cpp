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
#include "controller_editor.h"
#include "opencv2/imgcodecs.hpp"
#include <string>
#include <windows.h>

controller_editor::controller_editor(std::shared_ptr<i_img_editor> editor, std::vector<cv::Rect> faces, cv::Mat img, std::shared_ptr<view_editor> view) :
    m_editor(editor),
    m_img(img),
    m_view(view)
{
    m_view->show(); //TODO: evt. ans Ende

    //cv::cvtColor(m_img,m_img,cv::COLOR_BGR2RGB);
    QImage imdisplay((uchar*)m_img.data, m_img.cols, m_img.rows, m_img.step, QImage::Format_RGB888); //TODO: in eigene Funktion
    m_view->set_image(imdisplay);
    m_view->set_bounding_boxes(faces);

    m_editor->set_bounding_boxes(faces); //TODO: Überlegen ob ohne shared pointer
}

void controller_editor::click_save(std::vector<cv::Rect> bounding_boxes, std::string path) {
    m_editor->set_bounding_boxes(bounding_boxes);
    std::vector<portrait> portraits = m_editor->get_portraits();

    std::string file_name("portrait.jpg");
    int i=0;
    bool success=true;
    for(auto itr = portraits.begin(); itr != portraits.end(); ++itr){
        if(portraits.size()>1)
            file_name="portrait_" + std::to_string(++i) + ".jpg";
        if(!cv::imwrite(path+"/"+file_name, itr->get_img()))
            success=false;
        else {
            //std::string fullpath (path+"/"+file_name);
            //std::wstring widestr(fullpath.begin(),fullpath.end());
            //ShellExecute(GetDesktopWindow(), L"open", widestr.c_str(), NULL, NULL, SW_SHOWNORMAL);
        }

    }
    if(success){
        MessageBoxW(NULL,L"Portraits successfully saved!", L"Successful", MB_OK);
    }
    else
        MessageBoxW(NULL,L"Failed to save portraits!", L"Error", MB_ICONEXCLAMATION );


    //TODO: pfad nutzen + bild öffnen
}
