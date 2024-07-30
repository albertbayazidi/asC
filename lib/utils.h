#pragma once
#include <math.h>
#include <stdio.h>
#include <unistd.h>


unsigned char findMaxGrayscaleValue(unsigned char* data, const int size);

void remapGreyscale(unsigned char* data, int params, unsigned long size);
