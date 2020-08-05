cmake_minimum_required(VERSION 3.15)
project(MTM_Final_Project_20)

set(CMAKE_CXX_STANDARD 11)

include_directories(.)

add_executable(MTM_Final_Project_20
        Graph.cpp
        Graph.h
        Vertex.cpp
        Vertex.h
        Edge.cpp
        Edge.h Calculator.cpp Calculator.cpp Calculator.h)
