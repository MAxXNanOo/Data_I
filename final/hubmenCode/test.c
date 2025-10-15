#include <stdio.h>

int main()
{
    char myString[512];
    scanf("%s",myString);

    printf("%s",myString);

    myString[3] = 0;

    printf("\n\n%s\n\n",myString);

    for(int i=0 ; myString[i] != '\0' ; i++){
        printf("%c\n",myString[i]);
    }
}