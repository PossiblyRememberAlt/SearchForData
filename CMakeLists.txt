# Specify the minimum CMake version required
cmake_minimum_required(VERSION 3.10)

# Define the project name and language
project(SearchForData LANGUAGES CXX)

# Specify the C++ standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the executable target
add_executable(SearchForData main.cpp)