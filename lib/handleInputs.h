#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "argp.h"

static char args_doc[] = "path, resize, invert";

static struct argp_option options[] = { 
    { "path"  , 'p', 0, 0, "path to image"},
    { "resize", 'r', 0, 0, "resize Factor (optional)"},
    { "invert", 'i', 0, 0, "invert image color (optional)"},
    {0}
};

struct arguments{
    char *args[2];
    int invert;
};

static error_t
parse_opt (int key, char *arg, struct argp_state *state)
{
  struct arguments *arguments = state->input;

  switch (key)
    {
    case 'i': 
      arguments->invert = 1;
      break;

    case ARGP_KEY_ARG:
      if (state->arg_num >= 2)
        /* Too many arguments. */
        argp_usage (state);

      arguments->args[state->arg_num] = arg;

      break;

    case ARGP_KEY_END:
      if (state->arg_num < 2)
        /* Not enough arguments. */
        argp_usage (state);
      break;

    default:
      return ARGP_ERR_UNKNOWN;
    }
  return 0;
}

struct argp initialize_doc();

