#include "../lib/utils.h"

unsigned char findMaxGrayscaleValue(unsigned char* data, const int size){
    unsigned char currentLargesNr = 0;
    for(int i=0;i<size;i++){
        if (data[i] > currentLargesNr){
            currentLargesNr = data[i];
        }
        else{
            continue;
        }
            
    }
    return currentLargesNr;
}

void remapGreyscale(unsigned char* data, int imageSize, unsigned long size){
    unsigned char maxVal = findMaxGrayscaleValue(data,imageSize);
    for (int i = 0; i<imageSize;i++){
        float val = data[i]/(float)maxVal;
        data[i] = val*size;
    }
}
