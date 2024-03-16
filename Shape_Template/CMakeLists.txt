include_directories(${PROJECT_SOURCE_DIR}/deps/glfw-3.4/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/glm)
include_directories(${PROJECT_SOURCE_DIR}/Shader_Template)
include_directories("${PROJECT_SOURCE_DIR}/Setup")

add_library(ShapeTemplate rectangle.cpp)

target_include_directories(ShapeTemplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ShapeTemplate ShaderTemplate glad glfw glm)