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

set(
    NEEDED_DLL_FILES
    C:/Users/Acer/C_Language/C++/CPlusPlusLibs/SDL2_image/SDL_image-release-2.8.2/build/SDL2_image.dll
    C:/Users/Acer/C_Language/C++/CPlusPlusLibs/SDL2/SDL-release-2.30.1/build/SDL2.dll
)

foreach(FILE ${NEEDED_DLL_FILES})
    add_custom_command(
        TARGET ${PROJECT_NAME}
        POST_BUILD
        COMMAND ${CMAKE_COMMAND} -E copy_if_different
        ${FILE}
        ${CMAKE_CURRENT_BINARY_DIR}
    )
endforeach()

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC
    NTTEngine
)