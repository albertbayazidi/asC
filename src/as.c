#include "asc.h"
#include <stdio.h>
#include <string.h>

void printSimpleAsc(unsigned char *data, int *params, char *density, uint8_t threshold) {
    for (int y = 0; y < params[1]; y++) {
        for (int x = 0; x < params[0]; x++) {
            uint8_t r = data[(y * params[0] + x) * params[2] + 0];
            uint8_t g = data[(y * params[0] + x) * params[2] + 1];
            uint8_t b = data[(y * params[0] + x) * params[2] + 2];
            uint8_t gray = 0.2126f * r + 0.7152f * g + 0.0722f * b;

            if (gray < threshold) {
                printf("  ");
            } else {
                int index = (int)(gray / 255.0f * (strlen(density) - 1));
                printf("%c%c", density[index], density[index]);
            }
        }
        printf("\n");
    }
}

void printColoredAsc(unsigned char *data, int *params, char *density, uint8_t threshold) {
    int domColor;
    char *ansiColor;
    char *redAnsi = "\e[0;31m";
    char *greenAnsi = "\e[0;32m";
    char *blueAnsi = "\e[0;34m";
    char *whiteAnsi = "\e[0;37m";

    for (int y = 0; y < params[1]; y++) {
        for (int x = 0; x < params[0]; x++) {
            uint8_t r = data[(y * params[0] + x) * params[2] + 0];
            uint8_t g = data[(y * params[0] + x) * params[2] + 1];
            uint8_t b = data[(y * params[0] + x) * params[2] + 2];

            if (r > b) {
                domColor = r;
                ansiColor = redAnsi;

            } else if (g > r) {
                domColor = g;
                ansiColor = greenAnsi;

            } else {
                domColor = b;
                ansiColor = blueAnsi;
            }

            if (domColor < threshold) {
                printf("  ");
            } else {
                int index = (int)(domColor / 255.0f * (strlen(density) - 1));
                printf("%s%c%c%s", ansiColor, density[index], density[index], whiteAnsi);
            }
        }
        printf("\n");
    }
}
