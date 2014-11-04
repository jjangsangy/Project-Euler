/**
  * Segmented Prime Sieve
  *
  **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long *prime_sieve(long n)
{
  /**
    * Prime Sieve
    *
    * Generate primes up to sqrt(n)
    *
    **/

    // Prime Number Theroem to Estimate Array Size
    long n_root  = (long)ceill(sqrtl(n)+1);
    long count   = (long)(floor(1.3*(n_root/log(n_root))));

    long *table  = malloc(n_root * sizeof(long));
    long *primes = malloc(count  * sizeof(long));

    // Sieve
    long i, j;
    for (i=2; i<n_root; i++) table[i] = 1;
    for (i=2; i<n_root; i++) if (table[i])
        for (j=i; i*j<n_root; j++)
            table[i*j] = 0;

    // Memory Deallocation
    for (i=2,j=0; i<n_root; i++) if (table[i] == 1)
        primes[j++] = i;
    free(table);

    return primes;
}



long *seg_sieve(long start, long end)
{
  /**
    * Segmented Sieve
    *
    * Calculate Primes from range(start, end)
    *
    **/

    long i, j;
    long length = end - start + 1;

    // Primes up to sqrt(max)
    long *array  = malloc(length * sizeof(long));
    long *primes = prime_sieve(end);
    for (i=0; i<=length; i++)
        array[i] = 1;

    // Ranged Sieve
    for (i=0; primes[i]; i++)
        for (j = (start%primes[i]); j<=end; j+=primes[i]) if (array[j])
            array[j] = 0;

    free(primes);

    return array;
}


int main(int argc, char *argv[])
{
    // Get Input
    if (argc-1 != 2)
    {
        fprintf(stderr, "Error %s Requres 1 Argument\n", __FILE__);
        return EXIT_FAILURE;
    }

    long start = strtoul(argv[1], NULL, 10);
    long end  =  strtoul(argv[2], NULL, 10);

    // Run
    long *primes = seg_sieve(start, end);

    // Print Primes
    long i;
    for (i=0; i<end-start+1; i++) if (primes[i])
        printf("%ld\n", i+start);

    free(primes);

    return EXIT_SUCCESS;
}
