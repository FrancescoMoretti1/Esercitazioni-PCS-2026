cmake_minimum_required(VERSION 3.20)
project(esercitazione10)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Trova la libreria Eigen3
find_package(Eigen3 3.3 REQUIRED NO_MODULE)

add_executable(gradiente_coniugato main.cpp)
target_link_libraries(gradiente_coniugato Eigen3::Eigen)
