#include <stdio.h>
#include <stdlib.h>

struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

struct Treenode *Root = NULL;

int main()
{
    char input[50], ch;
    scanf("%s",&input);

     
    for(int i=1 ; input[i] != '\0' ; i++){
        ch = input[i];
        if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){

        }
    }
}

