#include <math.h>

/*
 * fibonacci.h
 *
 * Fast implementation of fibonacci sequences using
 * exponentiation by squaring.
 */

long long fibonacci(int n) {
    return lround((
        pow(0.5 + 0.5 * sqrt(5.0), n)  -
        pow(0.5 - 0.5 * sqrt(5.0), n)) /
            sqrt(5.0));
}

long long factorial(unsigned long int n) {
    return lround(exp(lgamma(n+1)));
}
