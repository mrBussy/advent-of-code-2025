cmake_minimum_required(VERSION 3.22)

project(advent-of-code-2025 
    VERSION 1.0.0
    LANGUAGES C)

# ----- Options -----
set(AOC_PUZZLE_INPUT_PATH "${CMAKE_CURRENT_SOURCE_DIR}/input/" CACHE PATH "Path to the puzzle input files")
set(TESTING ON CACHE BOOL "Enable testing")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ----- Compiler options -----
# On Debug build, enable debug symbols and warnings

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug mode enabled")
    add_compile_definitions(DEBUG)
    add_compile_options(-g -Wall -Wextra -Wpedantic -O0 )

    else()
    add_compile_options(-O3)
endif()

# ----- Global inclusions -----
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/include/configuration.h.in ${CMAKE_CURRENT_BINARY_DIR}/include/configuration.h @ONLY)
list(APPEND CMAKE_MODULE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/cmake")
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/include)
include(aoc)

# Add clogger as a subdirectory
add_subdirectory("3rd_party/clogger")
include_directories("3rd_party/clogger/src/")
include_directories("3rd_party/clogger/include/")

# ----- Source files -----
add_subdirectory(src)

# ----- Testing -----
if (TESTING)
    enable_testing()
    include(CTest)
    add_subdirectory(3rd_party/unity)
    add_subdirectory(tests)
endif()
