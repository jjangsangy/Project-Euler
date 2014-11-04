#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

long *sieve(int limit)
{
    long long i, j;
    long *primes = malloc(limit * sizeof(long));

    // Fill Array
    for (i=2; i<limit; i++)
        primes[i] = 1;

    // Sieve Away
    for (i=2; i<limit; i++)
        if (primes[i])
            for (j=i; i*j<limit; j++)
                primes[i*j] = 0;

    return primes;
}

int is_prime(int n)
{
    int i;
    for (i=2; i<n; i--)
        if (n % i == 1)
            return true;
    return false;
}

int main(int argc, char *argv[])
{
    int i, max = atoi(argv[1]);
    long *primes = sieve(max);

    // Print Out Primes
    for (i=3; i<max; i++)
        if (primes[i] == 1)
            printf("Prime: %i Check: %s\n", i,
                is_prime(i) ? "True": "False"
            );

    free(primes);

    return 0;
}
