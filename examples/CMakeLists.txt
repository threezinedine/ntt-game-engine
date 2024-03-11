set(
    EXCLUDE_EXAMPLES
)

file(
    GLOB 
    EXAMPLE_FOLDERS
    *
)

set(
    SOURCE_FILE_TO_COPY
    C:/Users/Acer/C_Language/ntt-game-engine/build/libNTTEngine.dll
)

foreach(EXAMPLE_FOLDER ${EXAMPLE_FOLDERS})
    if (IS_DIRECTORY ${EXAMPLE_FOLDER}) 
        message(STATUS "Add examples ${EXAMPLE_FOLDER}")
        add_subdirectory(${EXAMPLE_FOLDER})
    endif()
endforeach()