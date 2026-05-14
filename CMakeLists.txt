cmake_minimum_required(VERSION 3.20)

project(FennEngine)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(external/glfw)

add_subdirectory(engine)
add_subdirectory(sandbox)