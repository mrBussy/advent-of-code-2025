/*=====================================================================
 * @file   aoc.h
 * @brief  Header file for Advent of Code 2025 solutions.
 * @details 
 * This module contains function prototypes for the solutions
 * to the Advent of Code 2025 challenges, including Day 01 and Day 02
 * Parts 1 and 2.
 *
 * @author R. Middel
 * @date   2025-11-12
 *
 * @license
 *      SPDX‑License-Identifier: MIT
 *
 * @notes
 *   • clogger.h: For logging functionality.
 *   • Standard C Library: For input/output and standard utilities.
 *=====================================================================*/
#ifndef __AOC_AOC_H__
#define __AOC_AOC_H__

#include <clogger.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "configuration.h"

/* Exported function prototypes --------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    char* cells;
    uint32_t columns;
    uint32_t rows;
} grid_t;

typedef struct {
    uint32_t column;
    uint16_t row;
} position_t;

int32_t day01_part1(void);
int32_t day01_part2(void);

uint64_t day02_part1(void);
uint64_t day02_part2(void);

uint32_t day03_part1(void);
__uint128_t day03_part2(void);

uint32_t day04_part1(void);
uint32_t day04_part2(void);

uint32_t day05_part1(void);
uint64_t day05_part2(void);

uint64_t day06_part1(void);
uint64_t day06_part2(void);

#ifdef __cplusplus
}
#endif

#endif // __AOC_AOC_H__