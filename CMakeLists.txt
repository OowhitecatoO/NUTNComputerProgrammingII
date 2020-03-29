cmake_minimum_required(VERSION 3.15)
project(NUTNComputerProgrammingII)

set(CMAKE_CXX_STANDARD 17)
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static")

add_executable(ch1_pr6 src/ch1/pr6/ch1_pr6.cpp)
add_executable(ch1_pr7 src/ch1/pr7/ch1_pr7.cpp)
add_executable(ch2_pr1 src/ch2/pr1/ch2_pr1.cpp)
add_executable(ch2_pr4 src/ch2/pr4/ch2_pr4.cpp)
add_executable(ch2_pr5 src/ch2/pr5/ch2_pr5.cpp)
add_executable(ch3_pr9 src/ch3/pr9/ch3_pr9.cpp)
add_executable(ch3_pr11 src/ch3/pr11/ch3_pr11.cpp)