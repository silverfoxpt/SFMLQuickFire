cmake_minimum_required(VERSION 3.5.0)
project(QuickFire VERSION 0.1.0 LANGUAGES C CXX)

add_executable(QuickFire main.cpp)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glfw-3.4")
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glm")
add_subdirectory("${PROJECT_SOURCE_DIR}/Shader_Template")
add_subdirectory("${PROJECT_SOURCE_DIR}/Shape_Template")
add_subdirectory("${PROJECT_SOURCE_DIR}/Texture_Template")

# For OpenGL 4.6
add_subdirectory("${PROJECT_SOURCE_DIR}/deps/glad")
include_directories("${PROJECT_SOURCE_DIR}/Image_Load")
include_directories("${PROJECT_SOURCE_DIR}/Setup")

target_link_libraries(QuickFire
glad
glfw
glm
ShaderTemplate
ShapeTemplate
TextureTemplate
)


