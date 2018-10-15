cmake_minimum_required(VERSION 3.12)
project(t1_comerciales)
find_package(OpenCV REQUIRED HINTS /Users/sebastiandonoso/dependencias/opencv/share/opencv )


set(CMAKE_CXX_STANDARD 11)

add_executable(t1_comerciales main.cpp extraction.cpp extraction.hpp load_file.cpp loadFile.hpp pathFiles.cpp pathFiles.hpp lookSimilar.cpp)
target_include_directories(t1_comerciales PUBLIC ${OpenCV_INCLUDE_DIRS})
target_link_libraries(t1_comerciales ${OpenCV_LIBS})