/**
  * Segmented Prime Sieve Header
  *
  * Author: Sang Han
  *   Year: 2014
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

// Couldn't sell on Craigslist
void free_table(void **table);

void allocate_table(long **table, long size, long value);

long *seg_sieve(long start, long end);

long *prime_sieve(long n);

