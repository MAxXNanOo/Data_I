#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

void DisplayLL()
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("Node val=%d\n",ptr->data);

        ptr = ptr -> next;
    }
    printf("\n\n");
}

void DisplayAddressLL()
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("Node val=%d,add=%X\t",ptr->data,ptr);

        printf("Next node add=%X\n",ptr->next);

        ptr = ptr -> next;
    }
}

int main()
{
    srand(time(NULL));

    int n;
    scanf("%d",&n);

    struct node *newNode,*ptrNode = NULL;

    int i;
    for(i=n ; i>0 ; i--){
        newNode = (struct node *)malloc(sizeof(struct node));
        
        newNode->data = rand()%100;
        printf("%d  ",newNode->data);
        newNode->next = ptrNode;
        ptrNode = newNode;
    }
    head=ptrNode;

    printf("\n\n");
    //DisplayLL();
    DisplayAddressLL();

}

