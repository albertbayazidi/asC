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
    arguments.args[1] = NULL;
    arguments.invert = 0;

    struct argp argp = initialize_doc();

    argp_parse(&argp, argc, argv, 0, 0, &arguments);

    if (arguments.invert) {
        density = "n@#$0gfedcba?1!;:+=,.'      ";
    }

  printf ("arg1 = %s\n arg2 = %s\n invert or nah = %s\n",
          arguments.args[0],
          arguments.args[1],
          arguments.invert ? "yee": "nah");


    return 0;
}
