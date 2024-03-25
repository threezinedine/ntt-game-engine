set(
    EXCLUDE_VENDORS
)

file(
    GLOB
    VENDOR_FOLDERS
    *
)

foreach(VENDOR_FOLDER ${VENDOR_FOLDERS})
    if (IS_DIRECTORY ${VENDOR_FOLDER}) 
        # compare whether the vendor folder is sfml or not
        if(${VENDOR_FOLDER} STREQUAL ${CMAKE_CURRENT_SOURCE_DIR}/sfml)
            set(BUILD_SHARED_LIBS OFF)
        endif()
        
        message(STATUS "Add vendor: ${VENDOR_FOLDER}")
        add_subdirectory(${VENDOR_FOLDER})
    endif()
endforeach()
