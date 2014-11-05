/**
  * Segmented Prime Sieve Header
  *
  * Author: Sang Han
  *
  **/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// Used to Generate Bounds to Compute
// Frequency of Primes Distributions
static const float legendre_ratio;

struct Range {
    long start;
    long end;
};

long *seg_sieve(long start, long end);

long *prime_sieve(long n);

void free_table(void **table);
