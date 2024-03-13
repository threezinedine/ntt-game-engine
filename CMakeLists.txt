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
)

add_subdirectory(
    ./examples
)