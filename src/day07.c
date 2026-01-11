/*=====================================================================
 * @file   day07.c
 * @brief  Module for Day 07 solutions of Advent of Code 2025.
 * @details 
 * This module contains the implementations for solving Day 07,
 * Parts 1 and 2, of the Advent of Code 2025 challenges.
 * Each function reads the input data and processes it to produce
 * the respective results.
 * 
 * @author R. Middel
 * @date   2026-01-11
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

/**
 * @brief Solves Day 07 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 07.
 * @return uint32_t The result of Part 1, or EXIT_FAILURE on error.
 */
uint32_t day07_part1(void)
{
    clog_info(__FILE__, "Entering day07_part1 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day07.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    // first find the tachyon start location
    size_t beam_start_index = strchr(lines[0], 'S') - lines[0];

    if (0 == beam_start_index)
    {
        clog_error(__FILE_NAME__, "Cannot locate the start of the tachyon beam");
        return -EXIT_FAILURE;
    }

    // Convert the start into a tachyon beam for the following to work
    lines[0][beam_start_index] = '|';

    // Next, for each round, find if the beam(s):
    // 1. Can continue
    // 2. Need to split
    size_t line_length = strlen(lines[0]);
    size_t total_splits = 0;
    for(size_t line_index=1; line_index< line_count; line_index++) {
        for(size_t entry_index=1; entry_index<line_length; entry_index++) {
            switch (lines[line_index][entry_index])
            {
            case '.':
                // just copy the info from above and continue
                lines[line_index][entry_index] = lines[line_index-1][entry_index];
                break;

            case '^':
                if ('|' == lines[line_index - 1][entry_index]) {
                    lines[line_index][entry_index - 1] = '|';
                    lines[line_index][entry_index + 1] = '|';
                    total_splits++;
                };
                break;
            default:
                break;
            }
        }
    }

    free(lines);
    return total_splits;
}

/**
 * @brief Solves Day 07 Part 2 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 2 of Day 07.
 * @return uint32_t The result of Part 2, or EXIT_FAILURE on error.
 */
uint32_t day07_part2(void)
{

    clog_info(__FILE__, "Entering day07_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day07.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    free(lines);
    return 0;
}