#define STB_IMAGE_IMPLEMENTATION

#include "../lib/imageLoader.h"
#include "../lib/asc.h"

int params[3];
char* density = "      '.,=+:;!1?abcdefg0$#@N";


int main(int argc, char **argv){
    if (argc < 2){printf("Give path dumass"); return 1;}

    char* path = argv[1];
    unsigned char* img_data = loadImage(path,params);

    if (img_data == NULL){
        printf("feiled to load img \n");
        return 1;
    }

    printf("Loaded image with width: %d, height: %d, channels: %d\n", params[0], params[1], params[2]);


    printSimpleAsc(img_data,params,density);

    stbi_image_free(img_data);
    return 0;
}
