#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node *next;
}Node;

Node *head;

int main()
{
    char arr[30];
    printf("Enter String : ");
    scanf("%s",&arr);

    Node *newNode,*ptr,*preptr;

    int i,j,count=0;

    for(i=0 ; arr[i] != '\0' ; i++){

        newNode = (struct node *)malloc(sizeof(struct node));

        if(arr[i] == 'N'){
            i++;
            newNode->data = (int)arr[i] - 48;
            head = newNode;
            newNode->next = NULL;
        }
        else if(arr[i] == 'I'){
            i++;
            if(arr[i] == 'F'){
                i++;
                ptr = head;
                newNode->data = (int)arr[i] - 48;
                newNode->next = head;
                head = newNode;
            }
            else if(arr[i] == 'A'){
                i++;
                ptr = head;
                for(j=1 ; j<= (int)arr[i] - 48 ; j++){
                    preptr = ptr;
                    ptr = ptr->next ;
                }
                newNode->data = (int)arr[i+1] - 48;
                preptr->next = newNode;
                newNode->next = ptr;
                i++;
            }
            else if(arr[i] == 'L'){
                i++;
                while (ptr->next != NULL) {
                    preptr = ptr;
                    ptr = ptr->next;
                }
                newNode->data = (int)arr[i] - 48;
                newNode->next = NULL;
                ptr->next = newNode;
            }
        }
        else if (arr[i] == 'P'){
            ptr = head;
            while (ptr != NULL) {
                printf("%d", ptr->data);
                ptr = ptr->next;
            }
            printf("\n\n");
        }
        else if (arr[i] == 'S') {
            i++;
            ptr=head;
            count=1;
            while(ptr != NULL && ptr->data != (int)arr[i] - 48){
                count++;
                ptr = ptr->next;
            }
            if(ptr == NULL){
                count = -1;
            }

            printf("%d",count);
        }
    }
}