/**
 * @file test_aoc2025.c
 * @brief Unit tests for Advent of Code 2025 solutions.
 * This file contains unit tests for the solutions implemented
 * for Advent of Code 2025, specifically for Day 01 and Day 02 parts 1 and 2.
 * @author R. Middel
 * @date 2024-06-10
 * @version 1.0
 * @copyright Copyright (c) 2025 R. Middel
 */

#include <aoc.h>
#include <unity.h>

void test_day01_part1(void) { TEST_ASSERT_EQUAL_INT32(3, day01_part1()); }
void test_day01_part2(void) { TEST_ASSERT_EQUAL_INT32(6, day01_part2()); }

void test_day02_part1(void) { TEST_ASSERT_EQUAL_INT64(1227775554, day02_part1()); }
void test_day02_part2(void) { TEST_ASSERT_EQUAL_INT64(4174379265, day02_part2()); }

void test_day03_part1(void) { TEST_ASSERT_EQUAL_INT32(357, day03_part1()); }
void test_day03_part2(void) { TEST_ASSERT_EQUAL_INT64(3121910778619, day03_part2()); }

void test_day04_part1(void) { TEST_ASSERT_EQUAL_INT32(13, day04_part1()); }
void test_day04_part2(void) { TEST_ASSERT_EQUAL_INT32(43, day04_part2()); }

void test_day05_part1(void) { TEST_ASSERT_EQUAL_INT32(3, day05_part1()); }
void test_day05_part2(void) { TEST_ASSERT_EQUAL_INT32(14, day05_part2()); }

void setUp(void) { /* Nothing to do – placeholder for Unity */ }

void tearDown(void) { /* Nothing to do – placeholder for Unity */ }

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_day01_part1);
    RUN_TEST(test_day01_part2);

    RUN_TEST(test_day02_part1);
    RUN_TEST(test_day02_part2);

    RUN_TEST(test_day03_part1);
    RUN_TEST(test_day03_part2);

    RUN_TEST(test_day04_part1);
    RUN_TEST(test_day04_part2);

    RUN_TEST(test_day05_part1);
    RUN_TEST(test_day05_part2);
    return UNITY_END();
}