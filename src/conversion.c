/*=====================================================================
 * @file   conversion.c
 * @brief  Support for all kind of conversions.
 * @details 
 * This module contains support functions to perform conversions
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

#include "conversion.h"

void long_to_str(long value, char* buffer, size_t buffersize)
{
    if(NULL==buffer || 0 == buffersize) {
        return;
    }

    int n = snprintf(buffer, buffersize, "%ld", value);
    if (n < 0 || (size_t) n >= buffersize)
    {
        buffer[buffersize - 1] = '\0';
    }
}

int split_string(const char* src, char delim, char** left, char** right)
{
    const char* sep = strchr(src, delim); /* locate the delimiter */
    if (!sep)
        return EXIT_FAILURE; /* delimiter not found */

    /* lengths of the two pieces */
    size_t len1 = (size_t) (sep - src);
    size_t len2 = strlen(sep + 1);

    /* allocate space for each token (+1 for the terminating NUL) */
    *left = malloc(len1 + 1);
    *right = malloc(len2 + 1);
    if (!*left || !*right)
    { /* out‑of‑memory guard */
        free(*left);
        free(*right);
        return 2;
    }

    /* copy the characters */
    memcpy(*left, src, len1);
    (*left)[len1] = '\0';
    memcpy(*right, sep + 1, len2);
    (*right)[len2] = '\0';

    return EXIT_SUCCESS;
}

char* aoc_strdup(const char* s)
{
    size_t len = strlen(s) + 1; /* include terminating NUL */
    char* p = malloc(len);
    if (p)
        memcpy(p, s, len);
    return p;
}