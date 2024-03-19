cmake_minimum_required(VERSION 3.10)

project(NTTEngine)

file(
    GLOB
    ENGINE_SRC_FILES
    src/*.cpp
)

option(DEBUG "Debug mode" ON)

if (DEBUG)
    add_compile_definitions(_DEBUG)
endif()

add_subdirectory(./vendors)

# find SDL3
find_package(SDL3 REQUIRED PATHS C:/MinGW/SDL3)
find_package(SDL3_image REQUIRED PATHS C:/MinGW/SDL3_image)

add_library(
    ${PROJECT_NAME}
    SHARED
    ${ENGINE_SRC_FILES}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC 
    ./include
    ./interfaces
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    nlohmann_json
    SDL3::SDL3-shared
    SDL3_image::SDL3_image-shared
)

add_subdirectory(
    ./examples
)