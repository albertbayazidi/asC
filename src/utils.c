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
    static char buffer[2500];

    fread(buffer, 1, fileSize, fptr);
    buffer[fileSize] = '\0';
    fclose(fptr);
    return (buffer);
}



