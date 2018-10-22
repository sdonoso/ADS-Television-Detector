//
// Created by Sebastian Donoso on 15-10-18.
//
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include "lookSimilar.hpp"

std::tuple<int, std::string, int> nearest(const cv::Mat &frame, std::vector<std::vector<cv::Mat>> commercials,
                                          const std::vector<std::string> &comercialsNames) {
    /**
     * funcion que calcula la menor distancia entre el frame del video y los comerciales
     * */
    int i = 0;
    int numCom = commercials.size();
    double minDist = cv::norm(commercials[0][0], frame, cv::NORM_L2);
    std::tuple<int, std::string, int> selectComercialFrame(0, comercialsNames[0], 0);
    while (i < numCom) {
        int countFrame = 0;
        int framesNumber = commercials[i].size();
        while (countFrame < framesNumber) {
            double dist = cv::norm(commercials[i][countFrame], frame, cv::NORM_L2);
            if (dist < minDist) {
                minDist = dist;
                selectComercialFrame = std::make_tuple(i, comercialsNames[i], countFrame);
            }
            countFrame++;
        }
        i++;

    }
    return selectComercialFrame;


}

std::vector<std::tuple<int, std::string, int>> runNearest(const std::vector<std::string> &commercialsNames, const std::vector<std::vector<cv::Mat>> &commercials,
           const std::vector<cv::Mat> &video) {
    /**
     * entrega cada frame de  video a la funcion nearest, ademas se pasan los comerciales
     * */
    std::vector<std::tuple<int, std::string, int>> result;
    int i = 0;
    for (const cv::Mat &frame:video) {
        std::tuple<int, std::string, int> r = nearest(frame, commercials, commercialsNames);
        std::cout << i << " " << std::get<0>(r) << " " << std::get<1>(r) << " " << std::get<2>(r) << " " << std::endl;
        result.push_back(r);
        i++;
    }
    return result;

}