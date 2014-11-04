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
