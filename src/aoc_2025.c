#include <stdlib.h>
#include <stdio.h>
#include <clogger.h>

#include "aoc.h"

int main(void) {

    clog_info(__FILE__, "Starting Advent of Code 2025");
    printf("Advent of Code 2025\n");

    printf("%.*s\n", 80,
           "--------------------------------------------------------------------------------");
    printf("Part 1 Result: %u\n", day01_part1());
    printf("Part 2 Result: %u\n", day01_part2());

    return EXIT_SUCCESS;
}