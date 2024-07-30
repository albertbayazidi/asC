#define STB_IMAGE_IMPLEMENTATION

#include "../lib/utils.h"
#include "../lib/imageLoader.h"
#include "../lib/asc.h"

int params[3];
char* density = "N@#$?!;:+=,.' ";


int main(){
    char* path = "img/test.jpg";
    unsigned char* img_data = loadImage(path,params);
    int imageSize = params[0] * params[1] * params[2];

    if (img_data == NULL){
        printf("feiled to load img \n");
        return 1;
    }

    printf("Loaded image with width: %d, height: %d, channels: %d\n", params[0], params[1], params[2]);

    remapGreyscale(img_data,imageSize,strlen(density));

    for (int i=0;i<imageSize;i++){printf("%d ",img_data[i]);}

//    printSimpleAsc(img_data,params,density);

    stbi_image_free(img_data);
    return 0;
}
