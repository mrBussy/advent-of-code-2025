/*=====================================================================
 * @file   sort.c
 * @brief  Support for all kind of sort algorithm.
 * @details 
 * This module contains support functions to perform sorting
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

#include "sort.h"

char* quick_sort(char* array)
{
    size_t len = strlen(array);
    if (len < 2)
    {
        return array;
    }
    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = 0; j < len - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}
char* quick_sort_rev(char* array)
{
    size_t len = strlen(array);
    if (len < 2)
    {
        return array;
    }
    for (size_t i = 0; i < len - 1; i++)
    {
        for (size_t j = 0; j < len - i - 1; j++)
        {
            if (array[j] < array[j + 1])
            {
                char temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
    return array;
}