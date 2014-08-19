#include <stdio.h>
#include <stdlib.h>

void sieve(long long *primes, long long limit);

int main(int argc, char *argv[])
{
    if (argc-1 != 1) {
        printf("Needs atleast 1 argument: %d provided\n", argc-1);
        return 1;
    }

    long long limit = strtoul(argv[1], NULL, 10);
    long long primes[limit];

    sieve(primes, limit);

    return 0;
}

void sieve(long long *primes, long long limit) {
    long long i, j, z=1;

    // Fill array with 1's
    for (i=2; i<limit; i++)
        primes[i] = 1;

    // Enumerate through multiples
    for (i=2; i<limit; i++)
        if (primes[i])
            for (j=i; i*j<limit; j++)
                primes[i*j] = 0;

    // Print remaining
    for (i=2; i<limit; i++)
        if (primes[i])
            printf("%lldth prime = %lld\n", z++, i);

}
