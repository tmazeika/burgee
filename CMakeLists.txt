cmake_minimum_required(VERSION 3.6.2)
project(burgee)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_executable(burgee main.cpp window.cpp window.h glfw_exception.h shader.cpp shader.h renderable.h input.cpp input.h)

# glfw
find_library(GLFW_LIB glfw3)
target_link_libraries(burgee ${GLFW_LIB})

# opengl
find_library(OPENGL_LIB OpenGL)
target_link_libraries(burgee ${OPENGL_LIB})

# glew
find_library(GLEW_LIB GLEW)
target_link_libraries(burgee ${GLEW_LIB})
