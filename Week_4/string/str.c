#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

int main()
{
    char arr[30];
    printf("Enter String : ");
    scanf("%s",&arr);

    printf("%c",arr[5]);
}