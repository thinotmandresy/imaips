cmake_minimum_required(VERSION 3.20)
project(imaipd LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
    src/main.cpp
)

target_include_directories(${PROJECT_NAME}
    PRIVATE include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
    SUFFIX ".upl"
)
