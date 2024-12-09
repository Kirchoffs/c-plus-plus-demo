cmake_minimum_required(VERSION 3.14)

project(
    naive-logger
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 11)

include_directories(${CMAKE_SOURCE_DIR}/util)

add_executable(
    main
    main.cpp
    util/logger.cpp
)
