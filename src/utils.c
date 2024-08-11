#include "../lib/utils.h"


char* makeDocFromReadme(){
    FILE *fptr; 
    fptr = fopen("README.md", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fptr, 0, SEEK_END);
    long fileSize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);
    char *buffer = (char*)malloc(fileSize + 1); // +1 for the null terminator

    if (buffer == NULL) {
        printf("Memory allocation failed.\n");
        fclose(fptr);
        exit(1);
    }

    fread(buffer, 1, fileSize, fptr);
    buffer[fileSize] = '\0';
    fclose(fptr);
    return (buffer);
}

void handleInputs(){



}

void printHelp(int argc, char **argv) {
    if (argc > 1 && strcmp(argv[argc - 1], "-h") == 0) {
        printf("  --path     / -p        path to image\n");
        printf("  --resize   / -r        resize Factor (optional)\n");
        printf("  --invert  / -i        invert image color (optional)\n");
        printf("  --help     / -h        this information\n");
    }
}



