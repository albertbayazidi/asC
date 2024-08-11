#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "argp.h"


struct arguments{
    char *args[2];
    int invert;
};

struct argp initialize_doc();
