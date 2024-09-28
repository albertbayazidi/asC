#include "../lib/asc.h"

void printSimpleAsc(unsigned char *data, int *params, char *density) {
  for (int y = 0; y < params[1]; y++) {
    for (int x = 0; x < params[0]; x++) {
      int r = data[(y * params[0] + x) * params[2] + 0];
      int g = data[(y * params[0] + x) * params[2] + 1];
      int b = data[(y * params[0] + x) * params[2] + 2];
      float gray = 0.2126f * r + 0.7152f * g + 0.0722f * b;
      int index = (int)(gray / 255.0f * (strlen(density) - 1));
      printf("%c", density[index]);
    }
    printf("\n");
  }
}
