/*=====================================================================
 * @file   day01.c
 * @brief  Module for Day 01 solutions of Advent of Code 2025.
 * @details 
 * This module contains the implementations for solving Day 01,
 * Parts 1 and 2, of the Advent of Code 2025 challenges.
 * Each function reads the input data and processes it to produce
 * the respective results.
 * 
 * @author R. Middel
 * @date   2025-11-12
 *
 * @license
 *      SPDX‑License-Identifier: MIT
 *
 *  @notes
 *    * External dependencies:
 *     - CLogger: For logging functionality.
 *     - Standard C Library: For input/output and standard utilities.
 *=====================================================================*/
#include <stdio.h>
#include <string.h>

#include "aoc.h"
#include "conversion.h"
#include "io.h"
#include "sort.h"

/**
 * @brief Solves Day 03 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 03.
 * @return uint32_t The result of Part 1, or EXIT_FAILURE on error.
 */
uint32_t day03_part1(void)
{
    // Implementation for Day 01 Part 1
    clog_info(__FILE__, "Entering day03_part1 function");
    char** lines = NULL;
    size_t line_count = 0;
    uint32_t joltage = 0;

    if (EXIT_FAILURE == io_read_input("day03.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    for(size_t i=0; i<line_count; i++) {
        // Process each line as needed
        char* bank = aoc_strdup(lines[i]);

        uint8_t max_battery_1 = 0, index_max_battery_1 = 0;

        for (size_t index = 0; index < strlen(bank) - 1; index++)
        {
            if ((bank[index] - '0') > max_battery_1)
            {
                max_battery_1 = bank[index] - '0';
                index_max_battery_1 = index;
            }
        }
        uint8_t max_battery_2 = 0, index_max_battery_2 = 0;
        for (size_t index = index_max_battery_1+1; index < strlen(bank); index++)
        {
            if ((bank[index] - '0') > max_battery_2)
            {
                max_battery_2 = bank[index] - '0';
                index_max_battery_2 = index;
            }
        }
        clog_debug(__FILE__, "Max battery 1: %d at index %zu; Max battery 2: %d at index %zu; joltage: %d", max_battery_1,
                   index_max_battery_1, max_battery_2, index_max_battery_2, (max_battery_1 * 10) + max_battery_2);

        joltage += (max_battery_1 * 10) + max_battery_2;
        free(bank);
        }

    // Clean up and return failure as not implemented yet
    for(size_t i=0; i<line_count; i++) {
        free(lines[i]);
    }
    free(lines);
    return joltage;
}

/**
 * @brief Solves Day 03 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 03.
 * @return uint32_t The result of Part 2, or EXIT_FAILURE on error.
 */
uint64_t day03_part2(void)
{ // Implementation for Day 01 Part 1
    clog_info(__FILE__, "Entering day03_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day03.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    // Clean up and return failure as not implemented yet
    for (size_t i = 0; i < line_count; i++)
    {
        free(lines[i]);
    }
    free(lines);
    return EXIT_FAILURE;
}