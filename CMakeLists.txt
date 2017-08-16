cmake_minimum_required(VERSION 3.3)
project(Dotel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")

# Including GLFW
add_subdirectory(glfw)
include_directories(glfw/include)

set(SOURCE_FILES source/main.cpp source/Window.cpp source/Window.h)
add_executable(Dotel ${SOURCE_FILES})

# Linking GLFW
target_link_libraries(Dotel glfw ${GLFW_LIBRARIES})