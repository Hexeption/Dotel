cmake_minimum_required(VERSION 3.0.0)
project(Dotel)

add_subdirectory(Core)

add_subdirectory(OpenGL)

IF (WIN32)
    add_subdirectory(DirectX)
ENDIF ()

add_subdirectory(Demo)