#include <stdio.h>
#include <string.h>

int main()
{
    char a[50] = "abcde";
    char b[50] = "fghij";

    strncat(a,b,2);
    printf("%c",b[0]);
    printf("%s",a);
}