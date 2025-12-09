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
#include "io.h"
#include "conversion.h"

#define clog_debug(...) {}

#define MAX_CHAR_LENGTH_UINT64_T 20 

uint64_t return_value_if_invalid_id(uint64_t id) {

    char* value = malloc(sizeof(char) * MAX_CHAR_LENGTH_UINT64_T);
    long_to_str(id, value, MAX_CHAR_LENGTH_UINT64_T);
    size_t length = strlen(value);
    if (0!=(length & 1))
    {
        // uneven length is always valid
        return 0;
    }

    char *left = malloc(sizeof(char) * MAX_CHAR_LENGTH_UINT64_T),
         *right = malloc(sizeof(char) * MAX_CHAR_LENGTH_UINT64_T);

    strncpy(left, value, (length / 2));
    strncpy(right, value + (length/2), length / 2);
    left[(length / 2)] = '\0';
    right[(length / 2)] = '\0';
    clog_debug(__FILE__, "left: %s; right: %s", left, right);

    if (strcmp(left, right)==0)
    {
        free(left); 
        free(right);
        free(value);
        return id;
    }
    free(left);
    free(right);
    free(value);
    return 0; 
}

#define TRUE 1
#define FALSE 0

uint64_t return_value_if_invalid_id_part2(uint64_t id)
{

    char* value = malloc(sizeof(char) * MAX_CHAR_LENGTH_UINT64_T);
    long_to_str(id, value, MAX_CHAR_LENGTH_UINT64_T);
    size_t length = strlen(value);

    char *chunk_value;
    uint8_t value_is_invalid = TRUE;

    for(size_t chunk_size=1; chunk_size <= (length/2); chunk_size++) {

        chunk_value = value;
        value_is_invalid = TRUE;
        while(chunk_value!=NULL && chunk_value < (value + length)) {
            if (0 != strncmp(value, chunk_value, chunk_size)) {
                value_is_invalid = FALSE;
                break;
            }
            chunk_value += chunk_size;
        }
        if(value_is_invalid == TRUE) {
            free(value);
            return id;
        }
    }

    return 0;
}

/**
 * @brief Solves Day 02 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 02.
 * @return uint64_t The result of Part 1, or -EXIT_FAILURE on error.
 */
uint64_t
day02_part1(void)
{
    // Implementation for Day 01 Part 1
    clog_info(__FILE__, "Entering day02_part1 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day02.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    char *line = lines[0];

    char *start = NULL, *end = NULL;
    uint64_t result = 0;

    char* id_range = strtok(line, ",");
    while (id_range != NULL) {
        if (EXIT_SUCCESS == split_string(id_range, '-', &start, &end)) {
            clog_debug(__FILE__, "start: %s; end: %s", start, end);
        }
        else {
            clog_debug(__FILE__, "Error parsing %s", id_range);
        }

        // First check to see if the first value is correct
        if(start[0] >= '1' && start[0] <= '9') {

            // An invalid ID = any ID that has a repeating sequence of exactly 2 occurances
            for(size_t id = atol(start); id <= (size_t)atol(end); id++)
            {

                uint64_t res = return_value_if_invalid_id(id);
                if(res != 0) {
                    clog_debug(__FILE__, "Found value %d invalid;", res);
                }
                else {
                    clog_debug(__FILE__, "Found value %d valid;", id);
                }
                result += res;
            }

        }

        id_range = strtok(NULL, ",");
    }
    clog_debug(__FILE__, "Result %lu", result);
    
    free(lines);
    return result;
}

/**
 * @brief Solves Day 02 Part 2 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 2 of Day 01.
 * @return int32_t The result of Part 2, or -EXIT_FAILURE on error.
 */
uint64_t day02_part2(void)
{
    // Implementation for Day 01 Part 1
    clog_info(__FILE__, "Entering day02_part2 function");
    char** lines = NULL;
    size_t line_count = 0;

    if (EXIT_FAILURE == io_read_input("day02.txt", &lines, &line_count))
    {
        return -EXIT_FAILURE;
    }

    char* line = lines[0];

    char *start = NULL, *end = NULL;
    uint64_t result = 0;

    char* id_range = strtok(line, ",");
    while (id_range != NULL)
    {
        if (EXIT_SUCCESS == split_string(id_range, '-', &start, &end))
        {
            clog_debug(__FILE__, "start: %s; end: %s", start, end);
        }
        else
        {
            clog_debug(__FILE__, "Error parsing %s", id_range);
        }

        // First check to see if the first value is correct
        if (start[0] >= '1' && start[0] <= '9')
        {

            // An invalid ID = any ID that has a repeating sequence of exactly 2 occurances
            for (size_t id = atol(start); id <= (size_t) atol(end); id++)
            {

                uint64_t res = return_value_if_invalid_id_part2(id);
                if (res != 0)
                {
                    clog_debug(__FILE__, "Found value %d invalid;", res);
                }

                result += res;
            }
        }

        id_range = strtok(NULL, ",");
    }
    clog_debug(__FILE__, "Result %lu", result);

    free(lines);
    return result;
}