cmake_minimum_required(VERSION 3.0.0)
project(OpenGLTest)

#Boost libaries
set(Boost_USE_STATIC_LIBS ON CACHE BOOL "")
find_package(Boost 1.55 REQUIRED system unit_test_framework)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
        )

add_executable(${PROJECT_NAME} ${SOURCE_FILES})

# Require C++11
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 11)
set(CXX_STANDARD_REQUIRED ON)

# Core
target_link_libraries (${PROJECT_NAME} LINK_PUBLIC CoreLib)

# OpenGL
target_link_libraries (${PROJECT_NAME} LINK_PUBLIC OpenGLLib)

# Boost
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${Boost_LIBRARIES})
target_include_directories(${PROJECT_NAME} PUBLIC ${Boost_INCLUDE_DIR})