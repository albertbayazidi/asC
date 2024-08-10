#include "../lib/utils.h"

void printHelp(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[argc - 1], "-h") == 0) {
        printf("  --path     / -p        path to image\n");
        printf("  --resize   / -r        resize Factor (optional)\n");
        printf("  --inverse  / -i        invert image color (optional)\n");
        printf("  --help     / -h        this information\n");
    }
}
