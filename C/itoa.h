/*
 * itoa: convert n to characters in s
 *
 */

#include <string.h>
#include "reverse.h"

void itoa(int n, char s[])
{
    int i=0, sign;

    if ((sign = n) < 0)
        n = -n;

    do { s[i++] = n % 10 + '0'; }
    while ((n /= 10) > 0);

    if (sign < 0)
        s[i++] = '-';

    s[i] = '\0';

    reverse(s);
}
