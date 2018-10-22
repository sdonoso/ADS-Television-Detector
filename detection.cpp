//
// Created by Sebastian Donoso on 16-10-18.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <tuple>
#include <fstream>
#include "detection.hpp"
#include <iomanip>

void commercialsDetection(std::vector<std::tuple<int, std::string, int>> comparison) {
    int i = 0;
    int flag_b = 0;
    int flag_e = 0;
    int f_begin;
    int f_end;
    int count_end = 0;
    int n_com;
    int hit = 0;
    std::string name;
    std::tuple<int, int, std::string> detec;
    std::vector<std::tuple<int, int, std::string>> detections;
    for (std::tuple<int, std::string, int> res:comparison) {
        if (std::get<2>(res) < 15 && flag_b == 0) {
            f_begin = i;
            name = std::get<1>(res);
            n_com = std::get<0>(res);
            flag_b = 1;
            hit++;
        } else {

            if (std::get<0>(res) != n_com) {
                f_end = i;
                flag_e = 1;
            } else {
                hit++;
            }
            if (std::get<1>(res) != name && flag_e == 1) {
                count_end++;

            } else {
                count_end = 0;
            }
            if (count_end >= 10) {
                flag_b = 0;
                flag_e = 0;
                count_end = 0;
                if (hit >= 435) {

                    float sec_b = float(f_begin) / 30.0;
                    float sec_e = float(f_end) / 30.0;
                    detec = std::make_tuple(sec_b, sec_e - sec_b, name);
                    detections.push_back(detec);
                }
                hit = 0;

            }
        }
        i++;
    }

    std::ofstream myfile;
    myfile.open("detecciones.txt");
    for (std::tuple<int, int, std::string> detec:detections) {
        myfile << std::setprecision(2) << std::fixed << std::get<0>(detec) << "\t" << std::setprecision(2) << std::fixed
               << std::get<1>(detec) << "\t" << std::get<2>(detec) << std::endl;

    }


}