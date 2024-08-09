#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "../lib/imageUtils.h"
#include "../lib/asc.h"

// width, height, channels
int params[3];
char* density = "      '.,=+:;!1?abcdefg0$#@N";
unsigned char* resizedImage;
float resizeFactor = 0.5;

int main(int argc, char **argv){
    if (argc < 2){printf("Give path dumass"); return 1;}

    char* path = argv[1];
    unsigned char* img_data = loadImage(path,params);

    if (img_data == NULL){
        printf("feiled to load img \n");
        return 1;
    }

    resizedImage =  resizeImage(resizeFactor, img_data, params);

    printSimpleAsc(img_data,params,density);

    //freeing mem
    stbi_image_free(img_data);
    free(resizedImage);
    return 0;
}
