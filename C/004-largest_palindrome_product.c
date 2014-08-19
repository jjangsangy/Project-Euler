/*
 *
 * A palindromic number reads the same both ways.
 * The largest palindrome made from the product of two 2-digit numbers is
 *
 *    9009 = 91 × 99.
 *
 * Find the largest palindrome made from the product of two 3-digit numbers.
 *
 */

#include <stdio.h>
#include <string.h>
#include "itoa.h"

int is_palindrome(char* string) {
    int i, palindrome = 1;

    for (i=0; i<=(int)(strlen(string))/2; i++)
        if (string[i] != string[(int)(strlen(string))-i-1])
            palindrome = 0;

    return palindrome;
}

int main(void)
{
    char c[8];
    int i, j, solution=0;

    for (i=100; i<=1000; i++)
        for (j=100; j<=1000; j++) {
            itoa(i*j, c);
            if (is_palindrome(c) && i*j>solution)
                solution=i*j;
    }

    printf("Solution is %i\n", solution);
    return 0;
}

