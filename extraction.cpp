//
// Created by Sebastian Donoso on 01-10-18.
//
#include "extraction.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include <fstream>
#include <vector>


int extraction(std::string fileName) {
    //std::vector<uchar> frames_video;
    cv::VideoCapture capture;
    capture.open(fileName);
    if (!capture.isOpened()) {
        return -1;
    }
    std::cout << "extraction of video " << fileName << std::endl;
    int i = 0;
    std::vector<cv::Mat> frames_video;
    //extraer los frames de los videos
    while (capture.grab()) {
        if (i % 10 == 0) {
            cv::Mat frame, gray, final_f;
            if (!capture.retrieve(frame)) {
                continue;
            }
            cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
            cv::resize(gray, final_f, cv::Size(10, 10));
            final_f = final_f.reshape(1, 1);

            frames_video.push_back(final_f);


        }
        i++;


    }

    capture.release();
    cv::FileStorage framesVideo(fileName.substr(0, fileName.size() - 3) + "yml", cv::FileStorage::WRITE);
    framesVideo << "frames" << frames_video;
    framesVideo.release();

    return 0;

}

int videoExtraction(std::string file) {
    cv::VideoCapture capture;
    capture.open(file);
    int i = 0;

    if (!capture.isOpened()) {
        return -1;
    }
    std::cout << "extraction of video " << file << std::endl;
    std::vector<cv::Mat> frames_video;

    while (capture.grab()) {
        cv::Mat frame, gray, final_f;
        if (!capture.retrieve(frame)) {
            continue;
        }
        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY);
        cv::resize(gray, final_f, cv::Size(10, 10));
        final_f = final_f.reshape(1, 1);
        frames_video.push_back(final_f);
        std::cout << i++ << std::endl;

    }
    capture.release();
    cv::FileStorage framesVideo("video-prueba.yml", cv::FileStorage::WRITE);
    framesVideo << "frames" << frames_video;
    framesVideo.release();
    return 0;

}
