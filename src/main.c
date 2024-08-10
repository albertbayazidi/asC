#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "../lib/imageUtils.h"
#include "../lib/asc.h"
#include "../lib/utils.h"

// width, height, channels
int params[3];
char* density = "      '.,=+:;!1?abcdefg0$#@N";
char* inverseDensity = "N@#$0gfedcba?1!;:+=,.'      ";
float resizeFactor = 1.0;

int main(int argc, char **argv){
    
    //CHECK ARGS
    if (argc < 1){printf("Give path dumass"); exit(0);}


    char* path = argv[1];
    unsigned char* img_data = loadImage(path,params);

    if (argc > 2){
        resizeFactor = atof(argv[2]);
        unsigned char* resizedImage = resizeImage(resizeFactor, img_data, params);
        free(img_data);
        img_data = resizedImage;
    }

    printSimpleAsc(img_data,params,density);

    //freeing mem
    free(img_data);
    return 0;
}
