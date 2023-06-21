cmake_minimum_required(VERSION 3.0)

project(RandomGenerator-cli)

include_directories(include)

add_subdirectory(include)
add_subdirectory(src)

add_executable(RG-cli src/main.cpp)

target_link_libraries(RG-cli PUBLIC funcs)