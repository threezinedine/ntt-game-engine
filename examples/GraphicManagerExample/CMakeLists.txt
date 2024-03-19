project (
    GraphicManagerExample
)

file(
    GLOB
    GRAPHIC_MANAGER_EXAMPLE_SRC_FILES
    *.cpp
)

add_executable(
    ${PROJECT_NAME}
    ${GRAPHIC_MANAGER_EXAMPLE_SRC_FILES}
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    ${SOURCE_FILE_TO_COPY}
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    C:/MinGW/SDL3/bin/SDL3.dll
    ${CMAKE_CURRENT_BINARY_DIR}
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_if_different
    C:/MinGW/SDL3_image/bin/SDL3_image.dll
    ${CMAKE_CURRENT_BINARY_DIR}
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    NTTEngine
)