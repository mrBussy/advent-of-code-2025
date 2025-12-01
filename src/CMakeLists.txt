# ----- Configure the executable and sources -----
set(FULL_RUN_BINARY aoc_2025)
set(FULL_RUN_BINARY_SOURCES
    aoc_2025.c
    io.c
)

# ----- Build targets -----
add_executable(${FULL_RUN_BINARY}
    ${FULL_RUN_BINARY_SOURCES}
)

# --------- Add sources & add a specific .sh file ---------
aoc_add_puzzle(${FULL_RUN_BINARY} 1)
#aoc_add_puzzle(${FULL_RUN_BINARY} 2)

target_link_libraries(${FULL_RUN_BINARY} PRIVATE clogger)

# --------- Enable testing ---------
if (TESTING)
    set(AOC_LIBRARY aoc_2025_lib)

    add_library(${AOC_LIBRARY} STATIC
        io.c
        ${DAY01_SOURCES}
#        ${DAY02_SOURCES}
    )
    set(AOC_PUZZLE_INPUT_PATH "${CMAKE_SOURCE_DIR}/tests/inputs")
    # add AOC_PUZZLE_INPUT_PATH to the compile definitions
    message(STATUS "Setting AOC_PUZZLE_INPUT_PATH to ${AOC_PUZZLE_INPUT_PATH}")

    target_compile_definitions(${AOC_LIBRARY} PRIVATE AOC_PUZZLE_INPUT_PATH="${AOC_PUZZLE_INPUT_PATH}")

endif()