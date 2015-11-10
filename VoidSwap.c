// Proof of Concept code demonstrating the ability to abuse pointer
//   math to allow for a universal swap function.
// Using this code is probably not a great idea, but it is interesting.

#include <stdio.h>
#include <string.h>

void swap(void *a, void *b, int n);

struct DummyData {
    char name[20];
    int count;
};

int main() {
    int A = 5;
    int B = 17;

    double C = 2.2;
    double D = 8.88888;

    struct DummyData E;
    struct DummyData F;

    strcpy(E.name, "Bob");
    E.count = 27;

    strcpy(F.name, "Steve");
    F.count = 9000;

    printf("A was %d. B was %d\n", A, B);
    swap(&A, &B, sizeof(int));
    printf("A is  %d. B is  %d\n\n", A, B);

    printf("C was %0.2lf. D was %0.2lf\n", C, D);
    swap(&C, &D, sizeof(double));
    printf("C is  %0.2lf. D is  %0.2lf\n\n", C, D);

    printf("E was %s %d. F was %s %d\n", E.name, E.count, F.name, F.count);
    swap(&E, &F, sizeof(struct DummyData));
    printf("E is  %s %d. F is  %s %d\n\n", E.name, E.count, F.name, F.count);

    return 0;
}

void swap(void *a, void *b, int n) {
    char *x = a, *y = b, temp;
    int i;
    for (i = 0; i < n; i++){
        temp = x[i];
        x[i] = y[i];
        y[i] = temp;
    }
}
