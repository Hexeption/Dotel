cmake_minimum_required(VERSION 3.3)
project(Dotel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(Dependencies/glfw)
include_directories(Dependencies/glfw/include)

add_subdirectory(Dependencies/soil)
include_directories(Dependencies/soil/inc)

set(SOURCE_FILES source/main.cpp source/Window.cpp source/Window.h)
add_executable(Dotel ${SOURCE_FILES})

target_link_libraries(Dotel glfw ${GLFW_LIBRARIES} opengl32)