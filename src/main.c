#include <math.h>
#include <stdio.h>
#include <unistd.h>
#include "../lib/utils.h"

#define width 160
#define height 44

float cubeWidth = 10;
char buffer[width*height];

int main(){
    printf("Here we have the acctaul size of the matrix: %d \n",width*height);
    outputVec(buffer);
return 0;
}
