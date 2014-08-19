#include <stdio.h>
#include <stdlib.h>

long long fibonacci(int n);

int main(void)
{
    int i;
    int n=50;
    for (i=0; i<=n; i++)
        printf("Fibonacci of %02i is equal to %lld\n", i, fibonacci(i));

    return 0;
}

long long fibonacci(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return (fibonacci(n-1) + fibonacci(n-2));
}

