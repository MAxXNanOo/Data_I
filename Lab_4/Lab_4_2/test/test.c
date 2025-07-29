#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct node *next;
}node;

node *tail;

int main()
{
    node *newNode,*ptr=tail;

    for(int i=0 ; i<5 ; i++){
        newNode = (node *)malloc(sizeof(node));
        tail->next = newNode;
        newNode->data = i;
        newNode->next = ptr;
        ptr = newNode;
    }

    ptr = tail;
    while(ptr->next != tail){
        printf("\n %d",ptr->data);
        ptr = ptr->next;
    }
}