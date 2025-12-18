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
#include <getopt.h>

#include "aoc.h"


// Define long options
static struct option long_options[] = {{"day", required_argument, 0, 'd'},
                                       {"part", required_argument, 0, 'p'},
                                       {"help", no_argument, 0, 'h'},
                                       {0, 0, 0, 0}};

/**
 * @brief Main entry point for the Advent of Code 2025 solutions.
 * This function initializes logging, prints a header, and executes
 * the solutions for Day 1, Parts 1 and 2, displaying their results.
 * 
 * @param argc 
 *      Number of arguments passed to the application
 * @param argv
 *      Array of arguments passed (MAX argc)
 * 
 * @return int Exit status of the program.
 * 
 */
int main(int argc, const char **argv)
{
    clog_info(__FILE__, "Starting Advent of Code 2025");
    printf("Advent of Code 2025\n");

    // Variables for parsed arguments
    int day = 0;
    int part = 0; // 0 means run both parts
    int option_index = 0;

    // Parse command-line arguments
    int opt;
    while ((opt = getopt_long(argc, (char* const*) argv, "d:p:h", long_options, &option_index)) != -1)
    {
        switch (opt)
        {
            case 'd':
                day = atoi(optarg);
                clog_info(__FILE__, "Day set to: %d", day);
                break;
            case 'p':
                part = atoi(optarg);
                clog_info(__FILE__, "Part set to: %d", part);
                break;
            case 'h':
                printf("Usage: aoc_2025 [OPTIONS]\n");
                printf("Options:\n");
                printf("  --day <day>, -d <day>      Run solution for specific day (default: 1)\n");
                printf("  --part <part>, -p <part>   Run specific part: 1 or 2 (default: both)\n");
                printf("  --help, -h                 Display this help message\n");
                return EXIT_SUCCESS;
            case '?':
                // getopt_long already printed an error message
                return EXIT_FAILURE;
            default:
                break;
        }
    }


    printf("%.*s\n", 80, "--------------------------------------------------------------------------------");

    // Execute based on parsed arguments

    if ((1 == day || 0 == day) && (part == 0 || part == 1))
    {
        printf("Day 1 - Part 1 Result: %u\n", day01_part1());
    }
    if ((1 == day || 0 == day) && (part == 0 || part == 2))
    {
        printf("Day 1 - Part 2 Result: %u\n", day01_part2());
    }

    // Execute based on parsed arguments
    if ((2 == day || 0 == day) && (part == 0 || part == 1))
    {
        printf("Day 2 - Part 1 Result: %lu\n", day02_part1());
    }
    if ((2 == day || 0 == day) && (part == 0 || part == 2))
    {
        printf("Day 2 - Part 2 Result: %lu\n", day02_part2());
    }

    // Execute based on parsed arguments
    if ((3 == day || 0 == day) && (part == 0 || part == 1))
    {
        printf("Day 3 - Part 1 Result: %d\n", day03_part1());
    }
    if ((3 == day || 0 == day) && (part == 0 || part == 2))
    {
        printf("Day 3 - Part 2 Result: %llu\n", (long long unsigned int) day03_part2());
    }

    // Execute based on parsed arguments
    if ((4 == day || 0 == day) && (part == 0 || part == 1))
    {
        printf("Day 4 - Part 1 Result: %d\n", day04_part1());
    }
    if ((4 == day || 0 == day) && (part == 0 || part == 2))
    {
        printf("Day 4 - Part 2 Result: %d\n", day04_part2());
    }

    // Execute based on parsed arguments
    if ((5 == day || 0 == day) && (part == 0 || part == 1))
    {
        printf("Day 5 - Part 1 Result: %d\n", day05_part1());
    }
    if ((5 == day || 0 == day) && (part == 0 || part == 2))
    {
        printf("Day 5 - Part 2 Result: %d\n", day05_part2());
    }
    return EXIT_SUCCESS;
}