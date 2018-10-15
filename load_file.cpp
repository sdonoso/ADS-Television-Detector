//
// Created by Sebastian Donoso on 15-10-18.
//
#include "loadFile.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>


std::vector<cv::Mat> loadFile(std::string file) {
    cv::FileStorage fs2(file, cv::FileStorage::READ);
    std::vector<cv::Mat> framesVector;
    fs2["frames"] >> framesVector;
    fs2.release();

    return framesVector;

}