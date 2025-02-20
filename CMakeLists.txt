cmake_minimum_required(VERSION 3.14)
project(Mandelbrot CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Set external directory
set(EXTERNAL_DIR ${CMAKE_SOURCE_DIR}/external)

# Fetch rang.hpp if not found
if (NOT EXISTS "${EXTERNAL_DIR}/rang.hpp")
    message(STATUS "Downloading rang.hpp...")
    file(DOWNLOAD https://raw.githubusercontent.com/agauniyal/rang/master/include/rang.hpp
         ${EXTERNAL_DIR}/rang.hpp)
endif()

add_executable(mandelbrot main.cpp)
target_include_directories(mandelbrot PRIVATE ${EXTERNAL_DIR})
