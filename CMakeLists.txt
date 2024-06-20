cmake_minimum_required(VERSION 3.10)

SET(PROJECT_NAME "ntt-game-engine")

PROJECT(${PROJECT_NAME})

add_subdirectory(vendors)

file(
    GLOB_RECURSE
    SRC_FILES
    src/*.cpp
)

add_library(
    ${PROJECT_NAME}
    SHARED
    ${SRC_FILES}
)

target_include_directories(
    ${PROJECT_NAME}
    PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/interface
    ${CMAKE_CURRENT_SOURCE_DIR}/loader
)

add_subdirectory(examples)