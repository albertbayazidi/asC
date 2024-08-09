#pragma once
#include "./stb_image.h"
#include "./stb_image_resize2.h"

unsigned char* loadImage(char *path, int *params);

unsigned char* resizeImage(float resizeFactor, unsigned char* input_pixels, int* inputParams);
