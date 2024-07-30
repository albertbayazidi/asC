#define STB_IMAGE_IMPLEMENTATION

#include "../lib/utils.h"
#include "../lib/imageLoader.h"

#define width 160
#define height 44

float cubeWidth = 10;
char buffer[width*height];
int params[3];

int main(){
    char *path = "img/background.jpg";
    unsigned char* img_data = loadImage(path,params);

    if (img_data == NULL){
        printf("feiled to load img \n");
        return 1;
    }

    printf("Loaded image with width: %d, height: %d, channels: %d\n", params[0], params[1], params[2]);


    stbi_image_free(img_data);
    return 0;
    
}
