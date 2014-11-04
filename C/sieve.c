/**
  * The Sieve of Eratosthenes
  *
  * Sang Han
  *
  * Complexity:
  *     Space:  Worst: O(n^2/log(n))    Best: O(n/log(n))
  *      Time:  Worst: O(n*log(log(n))  Best: O(n*log(log(n))
  *
  **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

long *sieve(long limit)
{
  /* Sieve Algorithm */

  // Prime Number Theroem to Estimate Array Size
  long count = (long)(floor(1.2*(limit/log(limit))));

  long *table  = malloc(limit * sizeof(long));
  long *primes = malloc(count * sizeof(long));

  // Main Algorithm
  long i, j;
  for (i=2; i<limit; i++) table[i] = 1;
  for (i=2; i<limit; i++) if (table[i])
      for (j=i; i*j<limit; j++)
        table[i*j] = 0;

  // Memory Deallocation
  for (i=2,j=0; i<limit; i++) if (table[i] == 1)
      primes[j++] = i;
  free(table);

  return primes;
}

int main(int argc, char *argv[])
{
    // Get Input
    if (argc-1 != 1)
    {
        fprintf(stderr, "Error %s Requres 1 Argument\n", __FILE__);
        return EXIT_FAILURE;
    }

    // Run Sieve
    long i = 0, max = atol(argv[1]);
    long *primes = sieve(max);

    // Print Primes
    while (primes[i])
      printf("%ld\n", primes[i++]);

    free(primes);

    return EXIT_SUCCESS;
}
