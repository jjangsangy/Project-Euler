#include <stdio.h>

int main(void)
{
    int i, sum=0;
    for (i=1; i<1000; i++)
        sum = !(i%3) || !(i%5) ? sum+i: sum;

    printf("sum is %i\n", sum);

}
