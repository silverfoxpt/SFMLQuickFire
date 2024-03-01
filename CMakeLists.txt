cmake_minimum_required(VERSION 3.0.0)
project(ExerciseCpp VERSION 0.1.0 LANGUAGES C CXX)

include(CTest)
enable_testing()

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR "D:/C++ Libs/SFML-2.6.1/lib/cmake/SFML")

find_package(SFML 2.6 COMPONENTS graphics audio REQUIRED)
add_compile_options(-Wall -pedantic -Wno-unknown-pragmas)

add_executable(QuickFire main.cpp)
target_link_libraries(QuickFire sfml-graphics sfml-window sfml-system)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)


