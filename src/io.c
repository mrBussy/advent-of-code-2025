#include "aoc.h"
#include "io.h"

#include <clogger.h>

uint32_t io_read_input(const char *filename) {
    clog_info(__FILE__, "Reading input from file: %s", filename);
    // Implementation for reading input

    FILE *filep = fopen(filename, "r");

    if (filep == NULL) {
        clog_critical(__FILE__, "Failed to open file: %s", filename);
        return EXIT_FAILURE;
    }

    fclose(filep);
    return EXIT_SUCCESS;
}