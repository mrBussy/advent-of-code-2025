/*=====================================================================
 * @file   sort.h
 * @brief  Header file for sort.c.
 * @details 
 * This module contains function prototypes for the sorting functions
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
#ifndef __AOC_SORT_H__
#define __AOC_SORT_H__

#include <stdint.h>

/* Exported function prototypes --------------------------------------- */
#ifdef __cplusplus
extern "C" {
#endif

/**
 * @brief Sort a uint64_t array using quick sort algorithm
 * Sort the given uint64_t array in place using the quick sort algorithm
 * 
 * @param array uint64_t array to sort
 * @param len   length of the array
 * @return uint64_t* Pointer to the sorted character array
 */
uint64_t* quick_sort_uint64(uint64_t* array, size_t len);
/**
 * @brief Sort a character array using quick sort algorithm
 * Sort the given character array in place using the quick sort algorithm
 * 
 * @param array Character array to sort
 * @return char* Pointer to the sorted character array
 */
char* quick_sort(char* array);

/**
 * @brief Reverse Sort a character array using quick sort algorithm
 * Reverse Sort the given character array in place using the quick sort algorithm
 * 
 * @param array Character array to sort
 * @return char* Pointer to the Reverse sorted character array
 */
char* quick_sort_rev(char* array);

#ifdef __cplusplus
}
#endif

#endif // __AOC_SORT_H__