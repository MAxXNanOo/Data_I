#include <stdio.h>
#include <stdlib.h>

typedef struct Dnode{
    char ch;
    struct Dnode *next,*prev;
}Dnode;


Dnode* newNode(char v)
{
    Dnode *newNode = (Dnode *)malloc(sizeof(Dnode));
    newNode->ch = v;
}

int main()
{
    
}