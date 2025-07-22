#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node
{
    int data;
    struct node *next;
} node;

node *head = NULL;

void DisplayLL()
{
    struct node *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("Node val=%d\n",ptr->data);

        ptr = ptr -> next;
        if(ptr == head){
            break;
        }
    }
    printf("\n\n");
}

bool isCircular(node *h){
    node *ptr = h;
    do{
        if(ptr->next == NULL){
            return false;
        }
        ptr = ptr->next;
    }while(ptr != h);

    return true;
}



node *newNode(int v)
{
    node *new_node;
    new_node = (node *)malloc(sizeof(node));
    new_node->data = v;
    new_node->next = NULL;

    return new_node;
}
int main()
{
    head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    DisplayLL();
    printf("\n%d",isCircular(head));

    /*
    node *tail = head;
    if (!isCircular(head)){
        while(tail->next!=NULL){
            tail = tail->next;
        }
        tail->next = head;
    }
    
    printf("\n%d",isCircular(tail));
    */

    if (!isCircular(head)) {
        node *ptr = head;
        while(head->next != NULL){
            head = head -> next;
        }
        head->next = ptr;
        //head=head->next;
    }

    printf("\n%d",isCircular(head));

    DisplayLL();
}