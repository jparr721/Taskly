cmake_minimum_required(VERSION 3.9)
project(tetris LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR})
set(CMAKE_EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/lib})

find_package(Curses REQUIRED)
find_package(Threads REQUIRED)
include_directories("${PROJECT_SOURCE_DIR}/tuitetris/include"
  ${CURSES_INCLUDE_DIR}
)

add_executable(${PROJECT_NAME}
  "${PROJECT_SOURCE_DIR}/tuitetris/main.cc"
  "${PROJECT_SOURCE_DIR}/tuitetris/screen.cc"
)

target_link_libraries(
  ${PROJECT_NAME}
  ${CMAKE_THREAD_LIBS_INIT}
  ${CURSES_LIBRARIES}
)
