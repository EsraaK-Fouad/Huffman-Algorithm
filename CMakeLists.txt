cmake_minimum_required(VERSION 3.14)
project(sbe201_2019_final_project_sbe201_2021_team11)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(apps)
include_directories(include)

add_executable(sbe201_2019_final_project_sbe201_2021_team11
        apps/compress.cpp
        apps/decompress.cpp
        include/helpers.hpp
        include/huffman.hpp)
