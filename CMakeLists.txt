cmake_minimum_required(VERSION 3.7)

project(HelloWorld)
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(HelloWorld src/main.cpp)
target_link_libraries(HelloWorld ${SDL2_LIBRARIES})
