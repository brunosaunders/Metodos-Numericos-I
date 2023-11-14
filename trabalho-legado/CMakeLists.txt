cmake_minimum_required(VERSION 3.13.0)
set(CMAKE_CXX_STANDARD 17)

project(metodos LANGUAGES CXX)

add_executable(${PROJECT_NAME})

# Arquivos Executaveis
add_subdirectory(src)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/src)

# Arquivos Header
add_subdirectory(include)
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

