cmake_minimum_required(VERSION 3.7)

project(SDL2Test)

file(GLOB_RECURSE source_files
    "src/*.cpp")

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


add_executable(SDL2Test ${source_files})
target_link_libraries(SDL2Test ${SDL2_LIBRARIES})
target_include_directories(SDL2Test PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_compile_definitions(SDL2Test PRIVATE RESOURSE_PATH="${PROJECT_SOURCE_DIR}/res/")