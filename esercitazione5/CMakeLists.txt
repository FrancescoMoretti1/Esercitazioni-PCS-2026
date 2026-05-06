cmake_minimum_required(VERSION 3.20)
project(esercitazione5)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow")

add_executable(misuresorting timecounter.cpp misuresorting.cpp)
add_executable(test_all test_all.cpp)
add_test(NAME all_sorts COMMAND test_all)

enable_testing()
