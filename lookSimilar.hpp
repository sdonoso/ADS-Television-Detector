//
// Created by Sebastian Donoso on 16-10-18.
//

#ifndef T1_COMERCIALES_LOOKSIMILAR_H
#define T1_COMERCIALES_LOOKSIMILAR_H

#include <string>
#include <opencv2/opencv.hpp>
#include <vector>
#include <tuple>

std::tuple<int, std::string, int> nearest(const cv::Mat &frame, std::vector<std::vector<cv::Mat>> commercials,
                                          const std::vector<std::string> &comercialsNames);

std::vector<std::tuple<int, std::string, int>> runNearest(const std::vector<std::string> &commercialsNames, const std::vector<std::vector<cv::Mat>> &commercials,
                const std::vector<cv::Mat> &video);

#endif //T1_COMERCIALES_LOOKSIMILAR_H
