#include <string.h>

void reverse(char s[])
{
    int c, i, j;
    for (i = 0, j = strlen(s)-1; i < j; i++, j--)
        c = s[i], s[i] = s[j], s[j] = c;
}

/*
char *reverse(const char *s, char buffer[])
{

    // Returning a pointer to a Buffer Argument
    // rather than modifying in place.
    int i=0, j=strlen(s);

    while (j>0)
        buffer[i++] = s[--j];
    buffer[i] = '\0';

    return buffer;
}
*/
