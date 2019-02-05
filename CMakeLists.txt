cmake_minimum_required(VERSION 3.9)
project(bullet LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib})

include_directories("${PROJECT_SOURCE_DIR}/bullet/include")

add_executable(${PROJECT_NAME}
  "${PROJECT_SOURCE_DIR}/bullet/main.cc"
)
