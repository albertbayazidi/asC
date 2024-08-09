#include "../lib/imageUtils.h"

unsigned char* loadImage(char* path, int* params){
    unsigned char *img_data = stbi_load(path, &params[0], &params[1], &params[2], 0);
    return img_data;
}

unsigned char* resizeImage(float resizeFactor, unsigned char* input_pixels, int* inputParams){

    int new_width = inputParams[0] * resizeFactor;
    int new_height = inputParams[1] * resizeFactor;
    int channels = inputParams[2];

    unsigned char *output_pixels = (unsigned char*)
        malloc(new_width * new_height * channels);

    if (output_pixels == NULL) {
        printf("Failed to allocate memory for resized image\n");
        return NULL;
    }

    stbir_resize_uint8_srgb(input_pixels,
                       inputParams[0], inputParams[1], 0,
                       output_pixels,
                       new_width, new_height, 0,
                       channels);

    inputParams[0] = new_width;
    inputParams[1] = new_height;

    return output_pixels;

}

