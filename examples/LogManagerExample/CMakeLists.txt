project(
    LogManagerExample
)

file(
    GLOB
    LOG_MANAGER_EXAMPLE_SRC_FILES
    *.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${LOG_MANAGER_EXAMPLE_SRC_FILES}
)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SOURCE_FILE_TO_COPY}
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC 
    NTTEngine
)