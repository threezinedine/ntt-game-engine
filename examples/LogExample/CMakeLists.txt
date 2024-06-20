project(
    LogExample
)

add_executable(
    ${PROJECT_NAME}
    main.cpp
)

target_include_directories(
    ${PROJECT_NAME}
    PRIVATE
    C:/Users/Acer/C/ntt-game-engine/interface
    C:/Users/Acer/C/ntt-game-engine/loader
)