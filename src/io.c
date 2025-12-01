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
#include <string.h>

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
uint32_t io_read_input(const char* filename, char*** out_lines, size_t* out_line_count)
{
    char full_path[1024] = AOC_PUZZLE_INPUT_PATH;
    io_strcat(full_path, filename);
    clog_info(__FILE__, "Reading input from file: %s", full_path);

    FILE* fp = fopen(full_path, "r");
    if (!fp)
    {
        clog_critical(__FILE__, "Failed to open file: %s", full_path);
        return (uint32_t) EXIT_FAILURE;
    }

    size_t capacity = INITIAL_CAPACITY;
    char** lines = (char **)malloc(capacity * sizeof(char*));
    if (!lines)
    {
        fclose(fp);
        return (uint32_t) EXIT_FAILURE;
    }

    *out_line_count = 0;
    char buf[MAX_LINE_LEN];

    while (fgets(buf, sizeof buf, fp))
    {
        if (*out_line_count == capacity)
        {
            capacity *= 2;
            char** tmp = realloc(lines, capacity * sizeof(char *));
            if (!tmp)
            {
                clog_critical(__FILE__, "Error realloc");

                fclose(fp);
                return (uint32_t) EXIT_FAILURE;
            }
            lines = tmp;
        }

        /* strip trailing newline if you don’t want it */
        size_t len = strlen(buf);
        if (len && buf[len - 1] == '\n')
            buf[len - 1] = '\0';

        lines[*out_line_count] = (char *)malloc(MAX_LINE_LEN * sizeof(char));
        strncpy(lines[*out_line_count], buf, MAX_LINE_LEN);
        (*out_line_count)++;
    }

    if (ferror(fp))
    {
        clog_critical(__FILE__, "Error while reading");

        perror("Error while reading");
        fclose(fp);
        return (uint32_t) EXIT_FAILURE;
    }

    fclose(fp);
    *out_lines = lines;
    return (uint32_t) EXIT_SUCCESS;
}