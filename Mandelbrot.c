#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

#define XRATIO 5
#define YRATIO 3
#define BOUND 2.00
#define INITIAL 0

int Mand(double complex z, double complex c);
int MandCounter;

int main() {
    FILE* MandOut = fopen("MandOut.txt", "w");
    int GridMult = 11;
    int xGrid = XRATIO * GridMult;
    int yGrid = YRATIO * GridMult;
    int x, y;

    double complex C;

    for (y = 0; y < yGrid; y++) {
        for (x = 0; x < xGrid; x++) {
            MandCounter = 0;
            C = ((BOUND * -1) + (x * ((BOUND * 2)/(xGrid - 1)))) + (((BOUND * 1) + (y * ((BOUND * -2)/(yGrid - 1)))) * I);
            if (Mand(0, C)) {
                fprintf(MandOut, "*");
            } else {
                fprintf(MandOut, " ");
            }
        }
        fprintf(MandOut, "\n");
    }

    fclose(MandOut);
    return 0;
}

int Mand(double complex z, double complex c) {
    z = (z * z) + c;
    if (abs(creal(z)) > BOUND || abs(cimag(z)) > BOUND) {
        return 0;
    } else if (MandCounter > 1000) {
        return 1;
    } else {
        MandCounter++;
        Mand(z, c);
    }
}
