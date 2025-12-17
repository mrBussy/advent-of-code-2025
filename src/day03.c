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
        uint8_t max_battery_2 = 0;
        for (size_t index = index_max_battery_1+1; index < strlen(bank); index++)
        {
            if ((bank[index] - '0') > max_battery_2)
            {
                max_battery_2 = bank[index] - '0';
            }
        }
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
 * @brief  Find the largest possible number after removing exactly *k* digits.
 *
 * @details
 * Given a decimal string (e.g. <code>"234234234278"</code>) you may delete
 * exactly <em>k</em> characters while preserving the original order of the
 * remaining characters.  The goal is to obtain the numerically greatest value
 * that can be formed after the deletions.
 *
 * Example (k = 3):
 *
 * @code
 * original : 2 3 4 2 3 4 2 3 4 2 7 8
 * delete   : ^ ^   ^               (the first 2, the first 3, the second 2)
 * result   : 4 3 4 2 3 4 2 3 4 2 7 8  → 434234234278
 * @endcode
 *
 * This problem is the classic “maximum number after k deletions”
 * (also known as “largest number after removing k digits”).
 *
 * @param src  Null‑terminated source string from which the maximum number
 *             will be derived.
 * @param k    Number of characters to remove (0 ≤ k ≤ strlen(src)).
 *
 * @return A newly allocated null‑terminated string containing the maximal
 *         number.  The caller is responsible for freeing the returned buffer
 *         with <code>free()</code>.  If memory allocation fails, the function
 *         returns <code>NULL</code>.
 */
char* max_after_k_deletions(const char* src, int k)
{
    size_t src_length = strlen(src);
    if (k >= (int)src_length)
    { 
        // deleting everything → empty string
        char* empty = malloc(1);
        empty[0] = '\0';
        return empty;
    }

    /* Dynamic array acting as a stack */
    char* stack = malloc(src_length + 1); // +1 for terminating NUL
    size_t top = 0;              // number of elements in stack

    for (size_t char_index = 0; char_index < src_length; ++char_index)
    {
        char current_char = src[char_index];
        while (k > 0 && top > 0 && stack[top - 1] < current_char)
        {
            --top; // pop
            --k;
        }
        stack[top++] = current_char; // push
    }

    /* If deletions remain, drop from the end */
    while (k > 0 && top > 0)
    {
        --top;
        --k;
    }

    stack[top] = '\0'; // NUL‑terminate
    return stack;      // caller owns the buffer
}

/**
 * @brief Solves Day 03 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 03.
 * @return __uint128_t The result of Part 2, or EXIT_FAILURE on error.
 */
__uint128_t day03_part2(void)
{ // Implementation for Day 01 Part 1
    // Implementation for Day 01 Part 1
    clog_info(__FILE__, "Entering day03_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day03.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    __uint128_t total_joltages =0;
    for (size_t line_index = 0; line_index < line_count; line_index++)
    {
        // Process each line as needed
        char* bank = max_after_k_deletions(lines[line_index], strlen(lines[line_index]) - 12);
        total_joltages+=atoll(bank);
        free(bank);
    }

    // Clean up and return failure as not implemented yet
    for (size_t i = 0; i < line_count; i++)
    {
        free(lines[i]);
    }
    free(lines);
    return total_joltages;
}
