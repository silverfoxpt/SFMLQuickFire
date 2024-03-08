include_directories(${PROJECT_SOURCE_DIR}/deps/glfw-3.4/include)
include_directories(${PROJECT_SOURCE_DIR}/deps/glad/include)

add_library(ShaderTemplate shader.cpp)

target_include_directories(ShaderTemplate PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(ShaderTemplate glad glfw)