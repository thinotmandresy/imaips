cmake_minimum_required(VERSION 3.20)
project(imaips LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(${PROJECT_NAME} SHARED
  src/pugixml/pugixml.cpp

  src/ps/core.cpp
  src/ps/sps.cpp

  src/registry.cpp
  src/main.cpp
)

target_include_directories(${PROJECT_NAME}
  PRIVATE include
)

set_target_properties(${PROJECT_NAME} PROPERTIES
  SUFFIX ".upl"
)
