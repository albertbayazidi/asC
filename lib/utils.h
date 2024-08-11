#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "argp.h"

// Must free returned obj
char* makeDocFromReadme();

void printHelp(int argc, char **argv);


