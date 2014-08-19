#include <stdio.h>

int is_prime(long long n) {

    long long i;
    for (i=2; i<=n/2; i++) {
        if (n%i == 0) {
            return 1;
        }
    }

    return 0;
}

int main(void)
{

    long long n;
    for (n=600851475143; n>2; n--)
        if (is_prime(n) == 1)
            printf("%lld isnt prime", n);

    return 0;
}
