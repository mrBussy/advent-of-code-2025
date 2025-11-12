#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <clogger.h>

#include "aoc.h"
#include "io.h"

int32_t day01_part1(void) {
    // Implementation for Day 01 Part 1
    clog_info(__FILE__, "Entering day01_part1 function");

    if(EXIT_FAILURE == io_read_input("input/day01.txt")) {
        return -EXIT_FAILURE;
    }

    return 1;
}

int32_t day01_part2(void)
{
    // Implementation for Day 01 Part 2
    clog_info(__FILE__, "Entering day01_part2 function");

    return 0;
}

#ifdef RUN_STANDALONE
int main(void) {
    clog_info(__FILE__, "Entering day01 standalone main function");

    printf("Advent of Code 2025 - Day 1\n");

    int32_t result = day01_part1();
    if(result == -EXIT_FAILURE) {
        clog_error(__FILE__, "day01_part1 encountered an error reading input");
        return EXIT_FAILURE;
    }
    printf("Part 1 Result: %u\n", result);
    result = day01_part2();
    if (result == -EXIT_FAILURE)
    {
        clog_error(__FILE__, "day01_part1 encountered an error reading input");
        return EXIT_FAILURE;
    }
    printf("Part 2 Result: %u\n", result);

    clog_info(__FILE__, "Leaving day01 standalone main function");

    return EXIT_SUCCESS;
}
#endif