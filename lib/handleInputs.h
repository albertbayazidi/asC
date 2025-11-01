#pragma once

#include "argp.h"
#include <stdint.h>

struct arguments {
    char *args[1];
    int invert;
    float reszie_factor;
    uint8_t threshold;
    int color;
};

struct argp initialize_doc();
