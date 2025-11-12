cmake_minimum_required(VERSION 3.22)

project(advent-of-code-2025 
    VERSION 1.0.0
    LANGUAGES C)

# ----- Options -----
set(TESTING OFF CACHE BOOL "Enable testing")
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# ----- Compiler options -----
# On Debug build, enable debug symbols and warnings

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    message(STATUS "Debug mode enabled")
    add_compile_definitions(DEBUG)
    add_compile_options(-g -Wall -Wextra -Wpedantic -O0)
else()
    add_compile_options(-O3)
endif()

# ----- Global inclusions -----
include_directories(${PROJECT_SOURCE_DIR}/include)
include(${PROJECT_SOURCE_DIR}/cmake/add_day.cmake)

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
