//
// Created by Sebastian Donoso on 01-10-18.
//
#include <iostream>
#include <opencv2/opencv.hpp>


int extraction(std::string fileName) {
    cv::VideoCapture capture;
    capture.open(fileName);
    if (!capture.isOpened()) {
        return -1;
    }
    std::cout << "extraction of video" << fileName << std::endl;
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

            //TODO hacer ravel
            frames_video.push_back(final_f);

        }
        i++;


    }

    capture.release();
    //TODO guardar caracteristicas de comercial en memoria

}
