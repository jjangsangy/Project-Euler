import numpy as np

def set_sieve(n):
    """
    Sets are mutable, unordered collections which are useful
    for quick membership testing and math operations.
    """
    primes = set(range(2, n+1))
    for i in range(2, int(n**0.5)+1):
        if i in primes:
            primes -= set(range(i*i, n+1, i))
    return primes


def sieve(n):
    """Sieve away and only primes are left."""
    primes = 2 * [False] + (n - 1) * [True]
    for i in range(2, int(n**0.5+1)):
        for j in range(i*i, n+1, i):
            primes[j] = False
    return [prime for prime, checked in enumerate(primes) if checked]


def set_insertion_sieve(n):
    """Performing insertion over deletion"""
    factors = set()
    for i in range(2,int(n**0.5+1)):
        if i not in factors:
            factors |= set(range(i*i, n+1, i))
    return set(range(2,n+1)) - factors


def np_sieve(n):
    """
    Sieve with it's guts swapped with numpy
    ndarray
    """
    primes = np.ones(n+1, dtype=np.bool)
    for i in np.arange(2, n**0.5+1, dtype=np.uint32):
        if primes[i]:
            primes[i*i::i] = False
    return np.nonzero(primes)[0][2:]


surprise = lambda  very_math:     map(
           lambda __lololol_:  filter(
           (None),          (     map(
           lambda __suchwoow:     map(
           lambda __because___yolo__:\
         __lololol_.__setitem__(   ( (
         __because___yolo__ )  ),  (0)
         ),range(2 *   (__suchwoow), ( (very_math)),__suchwoow)
         ),range(2 ,    very_math )  ),(__lololol_))[1]  )[1:],
         [ range(       very_math )  ]                   )[0]
