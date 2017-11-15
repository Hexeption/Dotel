cmake_minimum_required(VERSION 3.0.0)
project(DirectXLib)

set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${project_SOURCE_DIR}/cmake")

add_subdirectory(external/sdl2)

file(GLOB_RECURSE SOURCE_FILES
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/source/*.h
        ${CMAKE_CURRENT_SOURCE_DIR}/include/*.h)

add_library(${PROJECT_NAME} ${SOURCE_FILES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANADARD 11)
set(CXX_STANDARD_REQUIRED ON)

target_link_libraries(${PROJECT_NAME} LINK_PUBLIC CoreLib)

#Private Includes
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/source)

#Public Includes
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

#SDL
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC ${SDL2_LIBRARIES})
target_link_libraries(${PROJECT_NAME} LINK_PUBLIC -lmingw32 -lSDL2main -lSDL2 -mwindows -lm -ldinput8 -ldxguid -ldxerr8 -luser32 -lgdi32 -lwinmm -limm32 -lole32 -loleaut32 -lshell32 -lversion -luuid -static-libgcc)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/external/sdl2/include)

