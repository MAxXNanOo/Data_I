#include <stdio.h>

#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node *head;

int main(){
    struct node *link,*link2,*link3;

    link = (struct node *)malloc(sizeof(struct node));

    head = link;

    link->data = 5;
    link->next = NULL;

    link2 = (struct node *)malloc(sizeof(struct node));

    link2->data = 6;

    link->next = link2;
    link2->next = NULL;

    link3 = (struct node *)malloc(sizeof(struct node));
    link3->data = 7;
    link2->next = link3;
    link3->next = NULL;


    // head -> 5 -> 6 -> 7 -> NULL
    struct node *ptr;
    ptr = head;
    for(int i=0 ; i<1 ; i++){
        ptr = ptr->next;
    }

    printf("%d",ptr->data);

}