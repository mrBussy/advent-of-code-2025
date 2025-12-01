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

#include <io.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_LINE_LEN 1024
#define INITIAL_CAPACITY 8

#if defined(_WIN32) || defined(_WIN64)
/* Windows */
#define PATH_SEPARATOR '\\'
#else
/* Anything POSIX‑like */
#define PATH_SEPARATOR '/'
#endif

/* Exported function prototypes --------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Concatenates two strings with a '/' separator.
 * This function appends the source string to the destination string,
 * adding a '/' between them if necessary.
 * @param dest The destination string.
 * @param src The source string to append.
 * @return char* Pointer to the concatenated string.
 */
char* io_strcat(char* dest, const char* src);
/**
 * @brief Reads input data from a specified file.
 * This function opens the file, reads its contents, and processes
 * the input data as required by the application.
 * @param filename The path to the input file.
 * @param lines Pointer to an array of strings to store the read lines.
 * @param line_count Pointer to a size_t variable to store the number of lines read.
 * @return uint32_t EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
uint32_t io_read_input(const char* filename, char*** out_lines, size_t* out_line_count);

#ifdef __cplusplus
}
#endif

#endif // __AOC_IO_H__
