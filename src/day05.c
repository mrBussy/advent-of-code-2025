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
    struct range {
        uint64_t start;
        uint64_t end_including;
    };

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

static unsigned char fresh_ingredients[10000] = {0};

/**
 * @brief Solves Day 05 Part 2 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 2 of Day 05.
 * @return uint32_t The result of Part 2, or EXIT_FAILURE on error.
 */
uint32_t
        day05_part2(void)
{

    clog_info(__FILE__, "Entering day05_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day05.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    size_t line_index = 0;
    uint64_t max_value=0;
    while (strlen(lines[line_index]) > 0)
    {
        uint64_t start, end;
        sscanf(lines[line_index], "%lu-%lu", &start, &end);

        for (uint64_t entry = start; entry <= end; entry++) {
            clog_debug(__FILE__, "%lu word %lu", entry, entry / 100000000000);
            //fresh_ingredients[entry % 706001751286] =
            //        1;
        }
        if(end > max_value) max_value = end;

        line_index++;
    }

    uint32_t sum=0;
    for (uint64_t id = 0; id <= max_value; ++id)
    {
        sum += fresh_ingredients[id];
    }

    free(lines);

    return sum;
}