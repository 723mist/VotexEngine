cmake_minimum_required(VERSION 3.5)
project(FluxEngine)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(OpenGL REQUIRED)
#find_package(glfw3 REQUIRED)

include_directories(SYSTEM /usr/include)
include_directories(SYSTEM /usr/include/GL)

add_library(gl3w libs/gl3w/src/gl3w.c)
target_include_directories(gl3w PUBLIC include)

file(GLOB_RECURSE SOURCES
        FluxEngine/*.cpp
        FluxEngine/Render/*.cpp
        FluxEngine/Texture/*.cpp
        FluxEngine/Window/*.cpp
)

file(GLOB_RECURSE HEADERS
        FluxEngine/*.h
        FluxEngine/Render/*.h
        FluxEngine/Objects/*.h
        FluxEngine/Vector/*.h
        FluxEngine/Matrix/*.h
        FluxEngine/Light/*.h
        FluxEngine/Camera/*.h

        FluxEngine/*.hpp
        FluxEngine/Window/*.hpp
        FluxEngine/Texture/*.hpp
        FluxEngine/Objects/*.hpp
        FluxEngine/Map/*.hpp
)      

add_executable(FE
        FluxEngine/main.cpp
        ${SOURCES}
        ${HEADERS}
)

target_include_directories(FE PRIVATE
        FluxEngine
        ${OPENGL_INCLUDE_DIR}
        #${GLEW_INCLUDE_DIRS}
)

target_link_libraries(FE PRIVATE
        gl3w
        OpenGL::GL
        glfw
        #GLEW::GLEW
)