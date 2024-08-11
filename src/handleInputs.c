#include "../lib/utils.h"
#include "../lib/handleInputs.h"

static char args_doc[] = "flag [PATH]";

static struct argp_option options[] = { 
    { "resize", 'r', "FACTOR", 0, "Resize factor (optional)"},
    { "invert", 'i', 0, 0, "Invert image color (optional)"},
    {0}
};

static error_t parse_opt (int key, char *arg, struct argp_state *state)
{
    struct arguments *arguments = state->input;

    switch (key)
    {
        case 'r': 
            arguments->reszie_factor = atof(arg); 
            break;

        case 'i': 
            arguments->invert = 1;
            break;

        case ARGP_KEY_ARG:
            if (state->arg_num >= 2)
                /* Too many arguments. */
                argp_usage(state);

            arguments->args[state->arg_num] = arg;
            break;

        case ARGP_KEY_END:
            if (state->arg_num < 1)
                /* Not enough arguments. */
                argp_usage(state);
            break;

        default:
            return ARGP_ERR_UNKNOWN;
    }
    return 0;
}

struct argp initialize_doc() {
    const char* doc = makeDocFromReadme();
    struct argp argp = { options, parse_opt, args_doc, doc };
    return argp;
}
