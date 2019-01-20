cmake_minimum_required(VERSION 3.0)

set (CMAKE_CXX_STANDARD 14)

project(OpenGLExercise)
add_executable(opengl_exercise main.cpp)

find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} )

target_link_libraries(opengl_exercise ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} )