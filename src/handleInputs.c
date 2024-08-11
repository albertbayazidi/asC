#include "../lib/utils.h"
#include "../lib/handleInputs.h"


struct argp initialize_doc() {
    char* doc = makeDocFromReadme();
    struct argp argp = { options, parse_opt, args_doc, doc };
    return argp;

}

