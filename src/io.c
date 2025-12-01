/*=====================================================================
 * @file   io.c
 * @brief  Module for input/output operations of Advent of Code 2025.
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
 *  @notes
 *    * External dependencies:
 *     - CLogger: For logging functionality.
 *     - Standard C Library: For input/output and standard utilities.
 *=====================================================================*/
#include "io.h"
#include "aoc.h"

/**
 * @brief Concatenates two strings with a '/' separator.
 * This function appends the source string to the destination string,
 * adding a '/' between them if necessary.
 * @param dest The destination string.
 * @param src The source string to append.
 * @return char* Pointer to the concatenated string.
 */
char* io_strcat(char* dest, const char* src)
{
    char* rdest = dest;

    while (*dest != '\0')
    {
        dest++;
    }
    if (*dest != PATH_SEPARATOR)
    {
        *dest = PATH_SEPARATOR;
        dest++;
    }
    while ((*dest++ = *src++) != '\0')
    {
        ;
    }

    return rdest;
}

/**
 * @brief Reads input data from a specified file.
 * This function opens the file, reads its contents, and processes
 * the input data as required by the application.
 * @param filename The path to the input file.
 * @return uint32_t EXIT_SUCCESS on success, or EXIT_FAILURE on error.
 */
uint32_t io_read_input(const char* filename)
{
    clog_info(__FILE__, "Reading input from file: %s", filename);

    char full_path[1024] = AOC_PUZZLE_INPUT_PATH;
    io_strcat(full_path, filename);

    FILE* filep = fopen(full_path, "r");
    if (filep == NULL)
    {
        clog_critical(__FILE__, "Failed to open file: %s", full_path);
        return EXIT_FAILURE;
    }

    fclose(filep);
    return EXIT_SUCCESS;
}