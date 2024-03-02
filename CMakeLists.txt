cmake_minimum_required(VERSION 3.5.0)
project(hellogl VERSION 0.1.0 LANGUAGES C CXX)

add_executable(hellogl main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glfw-3.4")

# For OpenGL 4.6
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glad")

target_link_libraries(hellogl
glad
glfw
)


