//
// Created by Sebastian Donoso on 15-10-18.
//

#ifndef T1_COMERCIALES_LOADFILE_H
#define T1_COMERCIALES_LOADFILE_H

#include <string>
#include <opencv2/opencv.hpp>
#include <vector>


std::vector<cv::Mat> loadFile(std::string file);

std::vector<std::vector<cv::Mat>> loadCommercials(const std::string &directory, std::vector<std::string> &namesCommercials);

#endif //T1_COMERCIALES_LOADFILE_H
