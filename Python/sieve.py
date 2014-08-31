def sieve(n):
    factors = set()
    for i in range(2,int(n**0.5+1)):
        [factors.add(j) for j in range(i*i, n+1, i)]
    return set(range(2,n+1))-factors

if __name__ == '__main__':
    print(sieve(100))
