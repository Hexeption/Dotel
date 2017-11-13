cmake_minimum_required(VERSION 3.0.0)
project(OpenGLLib)

#OpenGL
find_package(OpenGL REQUIRED)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "")
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "")
set(GLFW_BUILD_TESTS OFF CACHE BOOL "")
set(GLFW_INSTALL OFF CACHE BOOL "")
add_subdirectory(external/glfw)

file(GLOB SOIL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/external/soil/src/*.c)
set(THIRD_PARTY_SOURCES ${THIRD_PARTY_SOURCES} ${SOIL_SOURCES})

file(GLOB GLAD_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/src/*.c)
set(THIRD_PARTY_SOURCES ${THIRD_PARTY_SOURCES} ${GLAD_SOURCES})

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_library(${PROJECT_NAME} ${SOURCE_FILES} ${THIRD_PARTY_SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANADARD 11)
set(CXX_STANDARD_REQUIRED ON)

target_link_libraries (${PROJECT_NAME} LINK_PUBLIC CoreLib)

#Private Includes
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)

#Public Includes
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#GLFW
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${GLFW_LIBRARIES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC glfw)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glfw/include)

#GLAD
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/glad/include)

#SOIL
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/soil/inc)
