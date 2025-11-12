/*=====================================================================
 * @file   io.h
 * @brief  Header file for input/output operations of Advent of Code 2025.
 * @details 
 * This module contains functions for reading input data from files
 * and handling other I/O operations required by the Advent of Code 2025 solutions
 *
 * @author R. Middel
 * @date   2025-11-12
 *
 * @license
 *      SPDX‑License-Identifier: MIT
 *
 * @notes
 *      • Required compiler flags (e.g., -std=c11 for designated initializers).
 *      • Platform‑specific definitions (e.g., #ifdef _WIN32 …).
 *      • Dependencies on other public headers (list them here).
 *=====================================================================*/

#ifndef __AOC_IO_H__
#define __AOC_IO_H__

#include <stdint.h>

/* Exported function prototypes --------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

uint32_t io_read_input(const char *filename);

#ifdef __cplusplus
}
#endif

#endif // __AOC_IO_H__
