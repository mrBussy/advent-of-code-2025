/*=====================================================================
 * @file   day06.c
 * @brief  Module for Day 06 solutions of Advent of Code 2025.
 * @details 
 * This module contains the implementations for solving Day 06,
 * Parts 1 and 2, of the Advent of Code 2025 challenges.
 * Each function reads the input data and processes it to produce
 * the respective results.
 * 
 * @author R. Middel
 * @date   2025-12-30
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
#include "io.h"

#ifndef TESTING
    #define ROWS_WITH_NUMBERS 4
    #define COLUMNS_WITH_NUMBERS 1000
#else
    #define ROWS_WITH_NUMBERS 3
    #define COLUMNS_WITH_NUMBERS 4
#endif

/**
 * @brief Solves Day 06 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 06.
 * @return uint64_t The result of Part 1, or EXIT_FAILURE on error.
 */
uint64_t day06_part1(void)
{
    clog_info(__FILE__, "Entering day06_part1 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day06.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    // STORE THE NUMBERS
    uint32_t numbers[ROWS_WITH_NUMBERS+1][COLUMNS_WITH_NUMBERS+1];
    memset(numbers, 0, sizeof numbers);
    for (size_t row_index = 0; row_index < ROWS_WITH_NUMBERS; row_index++)
    {
        size_t column_index = 0;
        char* number = strtok(lines[row_index], " ");
        while (number != NULL)
        {
            numbers[row_index][column_index++] = atol(number);
            number = strtok(NULL, " ");
        }
    }

    // EXECUTE THE SUM
    size_t column_index = 0;
    char* action = strtok(lines[line_count-1], " ");
    uint64_t column_result=0;
    uint64_t total_sum = 0;
    while (action != NULL)
    {
        column_result = numbers[0][column_index];

        for(size_t row_index=1; row_index<ROWS_WITH_NUMBERS; row_index++) {
            switch(action[0]) {
                case '*':
                    column_result *= numbers[row_index][column_index];
                    break;
                case '+':
                    column_result += numbers[row_index][column_index];
                    break;
            }
        }
        total_sum += column_result;
        column_index++;
        action = strtok(NULL, " ");
    }

    free(lines);
    return total_sum;
}

/**
 * @brief Solves Day 06 Part 2 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 2 of Day 06.
 * @return uint32_t The result of Part 2, or EXIT_FAILURE on error.
 */
uint32_t day06_part2(void)
{

    clog_info(__FILE__, "Entering day06_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day06.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }


    free(lines);

    return 0;
}