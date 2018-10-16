//
// Created by Sebastian Donoso on 15-10-18.
//
#include "loadFile.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>
#include "pathFiles.hpp"


std::vector<cv::Mat> loadFile(std::string file) {
    cv::FileStorage fs2(file, cv::FileStorage::READ);
    std::vector<cv::Mat> framesVector;
    fs2["frames"] >> framesVector;
    fs2.release();

    return framesVector;

}

std::vector<std::vector<cv::Mat>>
loadCommercials(const std::string &directory, std::vector<std::string> &namesCommercials) {
    std::vector<std::vector<cv::Mat>> commercials;
    std::vector<std::string> list = listar_archivos(directory);
    for (std::string &fullpath : list) {
        commercials.push_back(loadFile(fullpath));
        std::string n = fullpath.substr(0,fullpath.size()-4 );
        namesCommercials.push_back(n.substr(directory.size() + 1, -1));
    }
    return commercials;


}