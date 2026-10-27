cmake_minimum_required(VERSION 3.25)

project(AlienPlanet
    VERSION 0.1.0
    LANGUAGES C CXX
)

set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

find_package(SDL3 CONFIG REQUIRED)

add_library(glad STATIC
    external/glad/src/gl.c
)

target_include_directories(glad PUBLIC
    external/glad/include
)

add_executable(alien-planet
    src/main.cpp
)

target_link_libraries(alien-planet PRIVATE
    SDL3::SDL3
    glad
)
