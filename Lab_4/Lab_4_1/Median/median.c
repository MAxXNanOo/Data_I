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

int main()
{
    srand(time(NULL));

    int n;
    printf("Enter n:");
    scanf("%d",&n);

    int i,j,arr[n],tmp,index,Median;
    for(i=0 ; i<n ; i++){
        arr[i] = rand() % 100;
        printf("%d ",arr[i]);
    }

    printf("\n");

    for(i=0 ; i<n-1 ; i++){
        tmp = arr[i];
        index=i;
        for(j=i+1 ; j<n ; j++){
            if(tmp > arr[j]){
                tmp = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = tmp;
        printf("%d ",arr[i]);
    }
    printf("%d",arr[i]);

    struct node *ptr,*newNode,*min=NULL,*max=head;
    for(i=n-1 ; i>=0 ; i--){
        newNode = (struct node *)malloc(sizeof(struct node));
        ptr = newNode;
        newNode->data = arr[i];
        newNode->next = head;
        head = ptr;
    }

    printf("\n\nEnter value of newnode: ");
    scanf("%d",&n);

    printf("\n\n");
    ptr = head;
    do{
        if(ptr->data <= n && ptr->next != NULL){
            max = ptr;
        }
        else{
            if(ptr->next == NULL){
                min = ptr;
                max = NULL;
            }else{
                min = max;
                max = ptr;
            }

            newNode = (struct node *)malloc(sizeof(struct node));
            newNode->data = n;
            if(head == ptr)
                head = newNode;
            else
                min->next = newNode;
            newNode->next = max;
            break;
        }
        ptr = ptr->next;
    }while(ptr != NULL);

    ptr = head;
    while(ptr != NULL){
        printf("%d  ",ptr->data);
        ptr = ptr->next;
    }

    printf("\n");
    DisplayLL();

}