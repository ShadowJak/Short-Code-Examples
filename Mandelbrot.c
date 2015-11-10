// This program creates a text file with a Mandelbrot graph centered on the origin.
// The math itself is simple but does use complex numbers.

#include <stdio.h>
#include <complex.h>
#include <stdlib.h>

// The X and Y Ratios are needed because characters aren't squares in the most
//   common fonts used in text files.
#define XRATIO 5
#define YRATIO 3

// The Bound is 2 by definition
#define BOUND 2.00

int Mand(double complex z, double complex c);
int MandCounter;

int main() {
    FILE* MandOut = fopen("MandOut.txt", "w");
    // GridMult can be used to change the size of the output
    int GridMult = 11;
    int xGrid = XRATIO * GridMult;
    int yGrid = YRATIO * GridMult;
    int x, y;

    double complex C;

    for (y = 0; y < yGrid; y++) {
        for (x = 0; x < xGrid; x++) {
            // MandCounter is used to determin the number of times to try the function before giving up.
            MandCounter = 0;
            // C is the complex number determined by the location in the graph. I is sqrt(-1)
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

// If the abs value of the function ever exceeds 2, the result is false.
// The counter is needed because the result will never exceed the bounds when true.
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
