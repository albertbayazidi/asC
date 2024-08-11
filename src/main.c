#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "../lib/imageUtils.h"
#include "../lib/asc.h"
#include "../lib/handleInputs.h"

const char *argp_program_version = "asC 0.1";
const char *argp_program_bug_address = "<albert.bayazidi@gmail.com>";

// width, height, channels
int params[3];
char* density = "      '.,=+:;!1?abcdefg0$#@N";

int main(int argc, char **argv){

    struct arguments arguments;

    arguments.args[0] = NULL;
    arguments.invert = 0;
    arguments.reszie_factor = 1.0;

    struct argp argp = initialize_doc();
    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    if (arguments.invert) {
        density = "N@#$0gfedcba?1!;:+=,.'      ";
    }

    unsigned char* img_data = loadImage(arguments.args[0],params);

    unsigned char* resizedImage = resizeImage(arguments.reszie_factor, img_data, params);
    free(img_data);
    img_data = resizedImage;

    printSimpleAsc(img_data,params,density);

    //freeing mem
    free(img_data);

    return 0;
}
