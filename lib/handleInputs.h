#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "argp.h"


struct arguments{
    char *args[1];
    int invert;
    float reszie_factor;
};


struct argp initialize_doc();
