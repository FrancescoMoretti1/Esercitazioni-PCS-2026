cmake_minimum_required(VERSION 3.10)
project(Esercitazione2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

add_executable(memoria memoria.cpp)
add_executable(algoritmi algoritmi.cpp)
