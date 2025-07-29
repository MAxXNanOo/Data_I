#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct node{
    int data;
    struct node *next;
};

struct node *head = NULL;

int search_item(int x)
{
    int countIndex=0;

    struct node *ptr=head;
    while(ptr != NULL){
        countIndex++;
        if(ptr->data == x){
            return countIndex;
        }
        ptr = ptr -> next;
    }
    return -1;
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

    printf("\n");
    printf("%d\n",search_item(65));
    printf("%d\n",search_item(50));
}
