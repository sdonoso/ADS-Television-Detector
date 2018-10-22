#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include "extraction.hpp"
#include "loadFile.hpp"
#include "pathFiles.hpp"
#include <vector>
#include "lookSimilar.hpp"
#include "detection.hpp"

int main(int argc, char **argv) {
    std::string direct = "/Users/sebastiandonoso/Documents/Universidad/2018/Recuperacion de la informacion/T1/comerciales/frames-c";
    std::vector<std::string> commercialsNames;
    std::vector<std::vector<cv::Mat>> commercials;
    commercials = loadCommercials(direct, commercialsNames);
    std::vector<cv::Mat> video = loadFile("video-prueba.yml");
    std::vector<std::tuple<int, std::string, int>> result = runNearest(commercialsNames, commercials, video);
    commercialsDetection(result);
    /*if (argc != 2) {
        std::cout << "debe escribir un directorio" << std::endl;
        return EXIT_FAILURE;
    }
    std::string dirname(argv[1]);
    std::vector<std::string> list = listar_archivos(dirname);
    for (const std::string &fullpath : list) {
        std::cout << fullpath << std::endl;
        //extraction(fullpath);
    }
    //std::vector<cv::Mat> frames = loadFile("/Users/sebastiandonoso/CLionProjects/t1_comerciales/ballerina.yml");
    return EXIT_SUCCESS;*/
    /*videoExtraction(
            "/Users/sebastiandonoso/Documents/Universidad/2018/Recuperacion de la informacion/T1/television/mega-2014_04_10.mp4");*/
    return 0;
}