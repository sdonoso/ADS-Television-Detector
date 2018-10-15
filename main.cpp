#include <iostream>
#include <opencv2/opencv.hpp>
#include <string>
#include "extraction.hpp"
#include "loadFile.hpp"
#include "pathFiles.hpp"
#include <vector>


int main(int argc, char **argv) {
    if (argc != 2) {
        std::cout << "debe escribir un directorio" << std::endl;
        return EXIT_FAILURE;
    }
    std::string dirname(argv[1]);
    std::vector<std::string> list = listar_archivos(dirname);
    for (const std::string &fullpath : list) {
        std::cout << fullpath << std::endl;
        extraction(fullpath);
    }
    //std::vector<cv::Mat> frames = loadFile("/Users/sebastiandonoso/CLionProjects/t1_comerciales/ballerina.yml");
    return EXIT_SUCCESS;
}