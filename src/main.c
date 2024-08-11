#define STB_IMAGE_IMPLEMENTATION
#define STB_IMAGE_RESIZE_IMPLEMENTATION

#include "../lib/imageUtils.h"
#include "../lib/asc.h"
#include "../lib/handleInputs.h"


// width, height, channels
int params[3];
char* density = "      '.,=+:;!1?abcdefg0$#@N";
float resizeFactor = 1.0;

int main(int argc, char **argv){

    struct arguments arguments;

    arguments.args[0] = NULL;
    arguments.args[1] = NULL;
    arguments.invert = 0;

    struct argp argp = initialize_doc();

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    if (arguments.invert) {
        density = "N@#$0gfedcba?1!;:+=,.'      ";
    }

  printf ("ARG1 = %s\n ARG2 = %s\n invert or nah = %s\n",
          arguments.args[0], arguments.args[1],
          arguments.invert ? "yee": "nah");


    return 0;
}
