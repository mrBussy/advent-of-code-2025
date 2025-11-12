# ----- Configure the executable and sources -----
set(FULL_RUN_BINARY aoc_2025)
set(FULL_RUN_BINARY_SOURCES
    aoc_2025.c
)

add_day(1)
add_day(2)

# ----- Build targets -----
add_executable(${FULL_RUN_BINARY}
    ${FULL_RUN_BINARY_SOURCES}
    ${DAY01_SOURCES}
    ${DAY02_SOURCES}
)

target_link_libraries(${FULL_RUN_BINARY} PRIVATE clogger)

if (TESTING)
    set(AOC_LIBRARY aoc_2025_lib)

    add_library(${AOC_LIBRARY} STATIC
        ${DAY01_SOURCES}
        ${DAY02_SOURCES}
    )
endif()