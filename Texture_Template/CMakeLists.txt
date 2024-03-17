include_directories(${PROJECT_SOURCE_DIR}/deps/glfw-3.4/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/glad/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/glm)
include_directories(${PROJECT_SOURCE_DIR}/Shader_Template)

include_directories("${PROJECT_SOURCE_DIR}/Setup")
include_directories("${PROJECT_SOURCE_DIR}/Image_Load")

add_library(TextureTemplate texture.cpp)

target_include_directories(TextureTemplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(TextureTemplate ShaderTemplate glad glfw glm)