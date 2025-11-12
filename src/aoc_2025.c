/*=====================================================================
 *  @file   aoc_2025.c
 *
 *  @brief  Main module for Advent of Code 2025 solutions.
 *
 *  @details This module serves as the entry point for executing the solutions
 *  to the Advent of Code 2025 challenges. It initializes logging,
 *  prints a header, and calls the solution functions for Day 1,
 *  Parts 1 and 2, displaying their results.
 *
 *  @author R. Middel
 *  @date   2025-11-12
 *
 *  @license
 *      SPDX‑License-Identifier: MIT
 *
 *  @notes
 *    * External dependencies:
 *     - CLogger: For logging functionality.
 *     - Standard C Library: For input/output and standard utilities.
 * 
 *=====================================================================*/
#include "aoc.h"

/**
 * @brief Main entry point for the Advent of Code 2025 solutions.
 * This function initializes logging, prints a header, and executes
 * the solutions for Day 1, Parts 1 and 2, displaying their results.
 * @return int Exit status of the program.
 * 
 */
int main(void)
{
    clog_info(__FILE__, "Starting Advent of Code 2025");
    printf("Advent of Code 2025\n");

    printf("%.*s\n", 80, "--------------------------------------------------------------------------------");
    printf("Part 1 Result: %u\n", day01_part1());
    printf("Part 2 Result: %u\n", day01_part2());

    return EXIT_SUCCESS;
}