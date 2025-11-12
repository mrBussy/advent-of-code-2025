set(TEST_PROJECT_NAME test_aoc_2025)

add_executable(${TEST_PROJECT_NAME}
    test_aoc2025.c)

target_link_libraries(${TEST_PROJECT_NAME} aoc_2025_lib unity clogger)   

add_test(test_aoc2025 ${TEST_PROJECT_NAME})
