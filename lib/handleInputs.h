#pragma once

#include "argp.h"

struct arguments {
    char *args[1];
    int invert;
    float reszie_factor;
};

struct argp initialize_doc();
