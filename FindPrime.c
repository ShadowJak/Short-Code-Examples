// Adrian Melendez
// Very simple functions to test for primality and find the next prime number.

#include <stdio.h>

// Pre-condition: value will be an integer greater than 1.
// Post-condition: Returns true (1) if value is prime, or
//     false (0) otherwise.
int isPrime(int value);

// Pre-condition: value will be an integer greater than 1.
// Post-condition: Returns the next prime number greater than or
//     equal to current.
int nextPrime(int current);

int main() {
    printf("Input an integer.\n");
    int value, twin;
    scanf("%d", &value);
    if (!isPrime(value)) {
        value = nextPrime(value);
        twin = nextPrime(value);
    } else {
        twin = nextPrime(value);
    }

    printf("%d and %d are ", value, twin);
    if (!(twin - value == 2))
        printf("not ");
    printf("twin primes.\n");

    return 0;
}

// The while loop works by incrementing x by 1 then taking the modulus
//     of value with respect to x. If the modulus is 0, the loop ends.
//     Eventually, x squared will be greater than value meaning which
//     means value is prime and the loop ends.
// Returns the outcome of a logical expression which is true when x
//     is prime as stated above. 2 is a special case because it is the
//     first prime and also is the first value of x checked.
int isPrime(int value) {
    int x = 1;
    while (value % ++x && value > x * x);
    return((value < x * x || value == 2) && value > 1);
}

// Recursive function that tests the primality of current. If prime,
//     returns current. Otherwise, calls itself with current incremented
//     by 1. It will keep calling itself until it finds a prime.
int nextPrime(int current) {
    while(!(isPrime(++current)));
    return current;
}
