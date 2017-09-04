cmake_minimum_required(VERSION 3.3)
project(Dotel)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(Dependencies/glfw)
include_directories(Dependencies/glfw/include)

add_subdirectory(Dependencies/soil)
include_directories(Dependencies/soil/inc)

include_directories(Dependencies/glew/include)
link_directories(Dependencies/glew/lib/Release/x64)

include_directories(Dependencies/glm)

file(GLOB SOURCE_FILES source/*.cpp source/*.h)
add_executable(Dotel ${SOURCE_FILES})

target_link_libraries(Dotel ${OPENGL_LIBRARIES} glfw ${GLFW_LIBRARIES} glew32s opengl32)