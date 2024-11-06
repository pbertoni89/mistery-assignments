cmake_minimum_required(VERSION 3.21)
project(mystery-assignments)

set(CMAKE_CXX_STANDARD 17)

add_executable (perceptron src/perceptron.cpp)

add_executable (monte-carlo src/monte-carlo.cpp)

add_executable (tree-search src/tree-search.cpp)

add_executable (atomic-async src/atomic-async.cpp)

add_executable (atomic-winner src/atomic-winner.cpp)

add_executable (pimpl src/main-pimpl.cpp src/pimpl.cpp)

add_executable (par-ser-race src/par-ser-race.cpp)

target_link_libraries (atomic-winner PRIVATE pthread)
