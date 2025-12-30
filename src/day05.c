/*=====================================================================
 * @file   day05.c
 * @brief  Module for Day 05 solutions of Advent of Code 2025.
 * @details 
 * This module contains the implementations for solving Day 05,
 * Parts 1 and 2, of the Advent of Code 2025 challenges.
 * Each function reads the input data and processes it to produce
 * the respective results.
 * 
 * @author R. Middel
 * @date   2025-11-18
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

typedef struct range {
    uint64_t start;
    uint64_t end_including;
} range_t;

/**
 * @brief Solves Day 05 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 05.
 * @return uint32_t The result of Part 1, or EXIT_FAILURE on error.
 */
uint32_t day05_part1(void)
{
    clog_info(__FILE__, "Entering day05_part1 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day05.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    size_t line_index = 0;


    struct range* fresh_ingredients_ids = malloc(sizeof(struct range));
    size_t range_capacity=1;
    while (strlen(lines[line_index]) > 0) {
        if (range_capacity <= line_index)
        {
            range_capacity = (line_index * 2);
            fresh_ingredients_ids = realloc(fresh_ingredients_ids, range_capacity * sizeof(struct range));
        }
        uint64_t start, end;
        sscanf(lines[line_index], "%lu-%lu", &start, &end);
        fresh_ingredients_ids[line_index].start = start;
        fresh_ingredients_ids[line_index].end_including = end;
        line_index++;
    }

    size_t range_size = line_index;
    line_index++; //skip empty line
    uint64_t available_ingredient_ids = 0;
    while (line_index < line_count)
    {
        uint64_t ingredient_id;

        ingredient_id = (uint64_t) atoll(lines[line_index]);
        size_t index=0;
        while (index < range_size) {
            if (ingredient_id >= fresh_ingredients_ids[index].start &&
                ingredient_id <= fresh_ingredients_ids[index].end_including) {
                    available_ingredient_ids++;
                    break;
                };
            index++;
        }
        line_index++;
    }

    free(lines);
    free(fresh_ingredients_ids);

    return available_ingredient_ids;
}

int range_compare(const void *left, const void *right) {
    const range_t *left_range = (const range_t *)left;
    const range_t *right_range = (const range_t *)right;
    
    if (left_range->start < right_range->start) return -1;
    if (left_range->start > right_range->start) return 1;
    return 0;
}

/**
 * @brief Solves Day 05 Part 2 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 2 of Day 05.
 * @return uint32_t The result of Part 2, or EXIT_FAILURE on error.
 */
uint64_t day05_part2(void)
{

    clog_info(__FILE__, "Entering day05_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day05.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    size_t range_size = 0;
    range_t ranges[line_count];

    while (range_size < line_count && '\n' != lines[range_size][0] && '\0' != lines[range_size][0])
    {
        uint64_t start, end;
        sscanf(lines[range_size], "%lu-%lu", &start, &end);
        ranges[range_size].start = start;
        ranges[range_size].end_including = end;
        range_size++;
    }

    qsort(ranges, range_size, sizeof(range_t), range_compare);

    size_t combined_range_size=0;
    range_t combined_ranges[range_size+1];
    memset(combined_ranges, 0, sizeof combined_ranges);

    combined_ranges[0].start = ranges[0].start;
    combined_ranges[0].end_including = ranges[0].end_including;

    for (size_t index = 0; index < range_size; index++)
    {
        // Check to see if the start > combined start and start < end_including
        if ((ranges[index].start <= combined_ranges[combined_range_size].end_including) &&
            (ranges[index].end_including > combined_ranges[combined_range_size].end_including))
        {
            combined_ranges[combined_range_size].end_including = ranges[index].end_including;
        }

        if (ranges[index].start > combined_ranges[combined_range_size].end_including)
        {
            combined_range_size++;
            combined_ranges[combined_range_size].start = ranges[index].start;
            combined_ranges[combined_range_size].end_including = ranges[index].end_including;
        }
    };

    __uint128_t sum=0;
    for (size_t index = 0; index <= combined_range_size; index++) {
        if (combined_ranges[index].end_including > 0 && combined_ranges[index].start > 0)
            sum += (combined_ranges[index].end_including - combined_ranges[index].start) + 1;
    }

    free(lines);

    // 324041339014962 <-- to low
    // next try: 332067203034711
    return sum;
}