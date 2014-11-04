#include <stdio.h>

long *sieve(long limit) {
    long long i, j;
    long *primes = malloc(limit * sizeof(long));
    
    for (i=2; i<limit; i++) primes[i] = 1;
    
    // Enumerate through multiples
    for (i=2; i<limit; i++)
        if (primes[i])
            for (j=i; i*j<limit; j++)
                primes[i*j] = 0;
    
    return primes;
}

int main(int argc, char *argv[])
{
    long max = 100;
    long *primes = sieve(max);
    
    int i;
    for (i=1; i<100; i++)
        if (*(primes+i) == 0)
            printf("%i\n", i);
    
    free(primes);
    return 0;
}
