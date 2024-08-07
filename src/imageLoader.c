#include "../lib/imageLoader.h"


unsigned char* loadImage(char* path, int* params){
    unsigned char *img_data = stbi_load(path, &params[0], &params[1], &params[2], 0);
    return img_data;
}

