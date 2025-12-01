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
#include <string.h>

#include "aoc.h"
#include "io.h"

/**
 * @brief Solves Day 01 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 01.
 * @return int32_t The result of Part 1, or -EXIT_FAILURE on error.
 */
int32_t day01_part1(void) {
    // Implementation for Day 01 Part 1
    clog_info(__FILE__, "Entering day01_part1 function");
    char **lines = NULL;
    size_t line_count = 0;

    if(EXIT_FAILURE == io_read_input("day01.txt", &lines, &line_count)) {
        return -EXIT_FAILURE;
    }

    int32_t dail = 50;
    size_t index = 0;
    size_t password = 0;

    while(index < line_count) {
        if (strncmp(lines[index], "L", 1) == 0)
        {
            dail = dail - atoi(&lines[index][1]) + 100;
        }
        else {
            dail += atoi(&lines[index][1]);
        }

        dail %= 100;
        if (dail == 0) {
            password++;
        }

        clog_debug(__FILE__, "The dail is rotated %s to point at %d", lines[index], dail);
        index++;
    }

    free(lines);
    return password;
}
/**
 * @brief Solves Day 01 Part 2 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 2 of Day 01.
 * @return int32_t The result of Part 2, or -EXIT_FAILURE on error.
 */
int32_t day01_part2(void)
{
    // Implementation for Day 01 Part 2
    clog_info(__FILE__, "Entering day01_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day01.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    int32_t dail = 50;
    size_t index = 0;
    size_t password = 0;
    int32_t rotate=0;
    size_t overflow = 0;

    while (index < line_count)
    {
        rotate = atoi(&lines[index][1]);

        if(rotate > 100) {
            overflow = (rotate / 100);
            rotate = rotate % 100;
        }

        if(strncmp(lines[index], "L", 1) == 0)
        {
            if(dail ==0 ) {
                dail = 100 - rotate;
            }
            else {
                dail = dail - rotate;
                if(dail < 0) {
                    dail += 100;
                    overflow += 1;
                }
                else if (dail == 0) {
                    overflow +=1;
                }
            }
        }
        else {
            dail += rotate;
            if (dail == 0)
            {
                password += 1;
            }
            if (dail >= 100)
            {
                dail %= 100;
                overflow += 1;
            }
        }

        password += overflow;
        if (overflow > 0)
        {
            clog_debug(__FILE__, "The dail is rotated %s to point at %d; during the rotation, it points to 0 %d times; password: %d", lines[index], dail, overflow, password);
        }
        else
            clog_debug(__FILE__, "The dail is rotated %s to point at %d; password: %d", lines[index], dail, password);

        overflow = 0;
        index++;
    }

    free(lines);
    return password;
}