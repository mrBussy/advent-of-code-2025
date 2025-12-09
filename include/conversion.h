/*=====================================================================
 * @file   conversion.h
 * @brief  Header file for input/output conversions
 * @details 
 * This module contains functions for all kind of conversions
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

#ifndef __AOC_CONVERSION_H__
#define __AOC_CONVERSION_H__

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* Exported function prototypes --------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief
 * Convert a long value to a string
 * 
 * @param value 
 *      Long value to convert
 * @param buffer 
 *      The buffer to store the value (cannot be NULL)
 * @param buffersize 
 *      The length of the buffer
 * 
 */
void long_to_str(long value, char* buffer, size_t buffersize);
/**
 * @brief 
 * Convert a string into seporate values
 * 
 * @param src   
 *      String to split
 * @param delim
 *      Delimiter to use
 * @param left
 *      Pointer to the left side
 * @param right
 *      Pointer to the right side
 * 
 * @return
 *  EXIT_SUCCESS if success; Else 2
 */
int split_string(const char* src, char delim, char** left, char** right);

#ifdef __cplusplus
}
#endif

#endif // __AOC_CONVERSION_H__
