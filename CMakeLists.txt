cmake_minimum_required(VERSION 3.21)
project(mystery-assignments)

set(CMAKE_CXX_STANDARD 17)

add_executable (perceptron src/perceptron.cpp)

add_executable (monte-carlo src/monte-carlo.cpp)

add_executable (tree-search src/tree-search.cpp)

add_executable (please-describe-me src/please-describe-me.cpp)

add_executable (atomic-winner src/atomic-winner.cpp)

target_link_libraries (atomic-winner PRIVATE pthread)
