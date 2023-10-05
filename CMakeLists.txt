cmake_minimum_required(VERSION 3.0)

project(metodos)

set(CMAKE_CXX_STANDARD 17)

file(GLOB SOURCES src/main.cpp src/*/*.cpp)

add_executable(metodos src/main.cpp ${SOURCES})

target_include_directories(metodos PUBLIC "${CMAKE_SOURCE_DIR}/include")


