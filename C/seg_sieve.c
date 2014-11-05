/**
  * Segmented Prime Sieve
  *
  * Author: Sang Han
  *   Year: 2014
  *
  * Segmented prime sieve implementation with trial division
  * up to sqrt(n) of max range to filter out composite values.
  * Utilizes the Sieve of Eratosthenes to for generating initial
  * primes.
  *
  * Time complexity is inferior to Sieve of
  * Eratosthenes, but much more memory efficient and useful
  * when only a subset of primes are needed.
  *
  **/

#include "seg_sieve.h"

#define free_index(t) free_table((void**)&(t))


void free_table(void **table)
{
    if (table != NULL && *table != NULL) {
        free(*table);
        *table = NULL;
    }
}

long *prime_sieve(long n)
{
    // Prime Number Theroem to Estimate Array Size
    long n_root = (long)(ceill(sqrtl(n)));
    long count = (long)(ceill(legendre_ratio * (n_root/log(n_root))));

    long *table  = (long*)malloc(n_root * sizeof(long));
    long *primes = (long*)malloc(count * sizeof(long));

    assert(tables != NULL && primes != NULL);

    for (long i=2; i<n_root; i++)
    {
        table[i] = 1;
    }

    // Sieve Composite Values
    for (long i=2; i<n_root; i++)
    {
        if (table[i]) {
            for (long j=i; i*j<=n_root; j++)
            {
                table[i*j] = 0;
            }
        }
    }

    // Memory Deallocation
    for (long i=2,j=0; i<n_root; i++)
    {
        if (table[i] == 1) {
            primes[j++] = i;
        }
    }

    free_index(table);

    return primes;
}

long *seg_sieve(long start, long end)
{
    long i, j;
    long length = end - start + 1;

    // Primes up to sqrt(max)
    long *array  = malloc(length * sizeof(long));
    long *primes = prime_sieve(end);

    assert(primes != NULL && array != NULL);

    for (i=0; i<length; i++)
    {
        array[i] = 1;
    }

    // Remove Composite Range
    for (i=0; primes[i]; i++)
    {
        for (j=(start%primes[i]); j<end; j+=primes[i])
        {
            array[j] = 0;
        }
    }

    free_index(primes);

    return array;
}

int main(int argc, char *argv[])
{
    // Get Input
    if (argc-1 != 2)
    {
        fprintf(stderr, "Error %s Requres 2 Argument\n", __FILE__);
        return EXIT_FAILURE;
    }

    struct Range range = {
        strtoul(argv[1], NULL, 10),
        strtoul(argv[2], NULL, 10),
    };

    // Run Sieve
    long *primes = seg_sieve(range.start, range.end);

    // Print Out For Range
    for (long i=0; i<range.end-range.start+1; i++)
    {
        if (primes[i]) {
            printf("%ld\n", i+range.start);
        }
    }

    free_index(primes);

    return EXIT_SUCCESS;
}
