/* euclid.c
 *
 * Euclidean Algorithm:
 *
 * Find the Greatest Common Divisor between two numbers.
 * A return value of 1 means that numbers are co-prime.
 *
 **/

#include <stdio.h>
#include <stdlib.h>

int gcd(int x, int y) {
    int remainder;

    // gcd(x, y) == gcd(y, remainder)
    while (y != 0) {
        remainder = x % y;
        x = y;
        y = remainder;
    }

    return x;
}

int main(int argc, char *argv[])
{
    int a, b, n;
    if (argc-1 != 2)
        printf("Needs an two args\n");

    a = atoi(argv[1]);
    b = atoi(argv[2]);
    n = gcd(a, b);

    printf("The Greatest Common Factor is %i\n", n);

    return 0;
}
