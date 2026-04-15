cmake_minimum_required(VERSION 3.20)
project(esercitazione4)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wshadow -Werror=vla")

# Target per prestazioni
add_executable(measure_sorts timecounter.cpp measure_sorts.cpp)

# Test unitari
foreach(alg bubblesort insertionsort selectionsort)
    add_executable(test_${alg} test_${alg}.cpp)
    add_test(NAME ${alg} COMMAND test_${alg})
endforeach()

enable_testing()
