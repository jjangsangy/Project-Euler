"""
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13,
we can see that the 6th prime is 13.

What is the 10,001st prime number?
"""

from sieve import np_sieve
from math import log


def prime_number_theorem(number):
    return number * log(number)


def main(prime):
    """
    Uses the prime number theorem to seed the first sieve.
    Recursively searches for the next range which is 2x larger than
    the original seed value. According to the prime number theorem,
    the nth prime should be within this range.

    Should only require sieving twice to get the correct solution.
    """
    start = np_sieve(prime_number_theorem(prime))
    estimate = len(start)

    if estimate > 10001:
        return start[10001-1]
    elif estimate == prime:
        return start[-1]
    else:
        return main(estimate*2)

if __name__ == '__main__':
    print(main(10001))
