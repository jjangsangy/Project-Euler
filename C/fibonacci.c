#include <stdio.h>
#include <math.h>

long long fibonacci(int n) {
    return lround((
        pow(0.5 + 0.5 * sqrt(5.0), n)  -
        pow(0.5 - 0.5 * sqrt(5.0), n)) /
            sqrt(5.0));
}

int main(void)
{
    int i, n=50;
    for (i=0; i<=n; i++)
        printf(
            "Fibonacci of %02i is equal to %lld\n", i, fibonacci(i));

    return 0;
}
