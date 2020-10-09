cmake_minimum_required(VERSION 3.7)

add_definitions(-std=c++17)
set(CXX_FLAGS "-Wall")
set(CMAKE_CXX_FLAGS, "${CXX_FLAGS}")

project(PingPong)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS} src)


add_executable(PingPong src/main.cpp src/gameLoop.cpp src/input.cpp src/renderer.cpp src/player.cpp src/ball.cpp src/computer.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)
target_link_libraries(PingPong ${SDL2_LIBRARIES})


