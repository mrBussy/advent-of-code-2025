#include <unity.h>
#include <aoc.h>

void test_day02_part1(void)
{
    TEST_ASSERT_NOT_EQUAL_INT32(0, day02_part1());
}
void test_day02_part2(void)
{
    TEST_ASSERT_EQUAL_INT32(0, day02_part2());
}

void test_day01_part1(void)
{
    TEST_ASSERT_NOT_EQUAL_INT32(0, day01_part1());
}
void test_day01_part2(void)
{
    TEST_ASSERT_EQUAL_INT32(0, day01_part2());
}

void setUp(void)
{
    /* Nothing to do – placeholder for Unity */
}

void tearDown(void)
{
    /* Nothing to do – placeholder for Unity */
}

int main(void)
{
    UNITY_BEGIN();
    RUN_TEST(test_day01_part1);
    RUN_TEST(test_day01_part2);

    RUN_TEST(test_day02_part1);
    RUN_TEST(test_day02_part2);

    return UNITY_END();
}