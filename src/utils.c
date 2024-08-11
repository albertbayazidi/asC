#include "../lib/utils.h"


const char* makeDocFromReadme(){
    static char buffer[2500];
    FILE *fptr = fopen("README.md", "r");

    if (fptr == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }

    fseek(fptr, 0, SEEK_END);
    long fileSize = ftell(fptr);
    fseek(fptr, 0, SEEK_SET);

    fread(buffer, 1, fileSize, fptr);
    buffer[fileSize] = '\0';
    fclose(fptr);
    return buffer;
}

