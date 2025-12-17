/*=====================================================================
 * @file   day04.c
 * @brief  Module for Day 04 solutions of Advent of Code 2025.
 * @details 
 * This module contains the implementations for solving Day 04,
 * Parts 1 and 2, of the Advent of Code 2025 challenges.
 * Each function reads the input data and processes it to produce
 * the respective results.
 * 
 * @author R. Middel
 * @date   2025-11-17
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
 * @brief find the number of rolls adjecent to the current cell
 */
int8_t find_adjacent_roll_count(grid_t *grid, uint32_t row, uint32_t column)
{
    if (column > grid->columns || row > grid->rows)
        return EXIT_FAILURE;

    /* Relative row/column deltas for the 8 neighbours */
    static const int direction_row[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    static const int direction_column[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
    unsigned hits = 0U;

    for (int i = 0; i < 8; ++i)
    {
        int nr = (int) row + direction_row[i]; /* neighbour row (may be negative) */
        int nc = (int) column + direction_column[i]; /* neighbour column */

        /* Boundary test – skip neighbours that fall outside the grid */
        if (nr < 0 || nr >= (int) grid->rows || nc < 0 || nc >= (int) grid->columns)
            continue;

        /* Index into the flat buffer (row‑major order) */
        size_t idx = (size_t) nr * grid->columns + (size_t) nc;

        if (grid->cells[idx] == '@')
            hits++;
    }

    return hits;
}
/**
 * @brief Solves Day 04 Part 1 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 1 of Day 04.
 * @return uint32_t The result of Part 1, or EXIT_FAILURE on error.
 */
uint32_t day04_part1(void)
{
    grid_t* grid = malloc(sizeof(grid_t));

    if (EXIT_FAILURE == io_read_grid("day04.txt", grid))
    {
        return -EXIT_FAILURE;
    }
    
    uint32_t total_roll_count=0;
    for (size_t row = 0; row < grid->rows; row++)
    {
        for(size_t col = 0; col < grid->columns; col++) {
            if('@' == grid->cells[(row*grid->columns) + col]) {
                int8_t hits = find_adjacent_roll_count(grid, row, col);
                total_roll_count += (hits >= 0 && hits < 4);
            }
        }

    }

    free(grid->cells);
    free(grid);
    return total_roll_count;
}
/**
 * @brief Solves Day 04 Part 2 of Advent of Code 2025.
 * This function reads the input data and processes it to produce
 * the result for Part 2 of Day 04.
 * @return uint32_t The result of Part 2, or EXIT_FAILURE on error.
 */
uint32_t day04_part2(void)
{
    grid_t* grid = malloc(sizeof(grid_t));

    if (EXIT_FAILURE == io_read_grid("day04.txt", grid))
    {
        return -EXIT_FAILURE;
    }

    size_t buf_size = grid->columns * grid->rows;
    char* stack = malloc(buf_size);
    if (NULL == stack) {
        free(grid->cells);
        free(grid);
        return -EXIT_FAILURE;
    }
    /* initialize stack with current grid contents to avoid uninitialized writes */
    memcpy(stack, grid->cells, buf_size);
    uint32_t total_roll_count = 0;
    uint32_t rolls_this_round = 0;

    do
    {
        rolls_this_round= 0 ;
        for (size_t row = 0; row < grid->rows; row++)
        {
            for (size_t col = 0; col < grid->columns; col++)
            {
                size_t idx = (row * grid->columns) + col;
                if ('@' == grid->cells[idx])
                {
                    int8_t hits = find_adjacent_roll_count(grid, row, col);
                    if (hits >= 0 && hits < 4) {
                        stack[idx] = '.';
                        rolls_this_round++;
                        total_roll_count++;
                    } else {
                        stack[idx] = '@';
                    }
                } else {
                    /* keep non-@ cells as they are (e.g. '.') */
                    stack[idx] = grid->cells[idx];
                }
            }
        }
        memcpy(grid->cells, stack, buf_size);
    } while (rolls_this_round > 0);
    free(stack);
    free(grid->cells);
    free(grid);
    return total_roll_count;
}
