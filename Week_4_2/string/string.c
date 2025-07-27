#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next,*prev;
};

struct node *head=NULL,*tail=NULL;

int toInt(char a)
{
    return (int)(a) - 48;
}

int main()
{
    char arr[30];
    scanf("%s",arr);

    int i,j;

    struct node *newNode,*ptr,*preptr;

    for(i=0 ; arr[i] != '\0' ; i++){

        newNode = (struct node *)malloc(sizeof(struct node));

        if(arr[i] == 'N'){
            newNode->prev = NULL;
            newNode->data = toInt(arr[i+1]);
            newNode->next = NULL;
            head = newNode;
            tail = newNode;
            i++;
        }
        else if(arr[i] == 'I'){
            i++;
            if(arr[i] == 'F'){
                i++;
                ptr = head;
                newNode->data = toInt(arr[i]);
                newNode->prev = NULL;
                newNode->next = ptr;
                ptr->prev = newNode;
                head = newNode;
            }
            else if(arr[i] == 'A'){
                i++;
                ptr = head;
                for(j=0 ; j<toInt(arr[i]) ; j++){
                    preptr = ptr;
                    ptr = ptr->next;
                }
                i++;
                preptr->next = newNode;
                newNode->data = toInt(arr[i]);
                newNode->prev = preptr;
                
                if(ptr == NULL){
                    newNode->next = NULL;
                    tail = newNode;
                }
                else{
                    newNode->next = ptr;
                    ptr->prev = newNode;
                }
                
            }
            else if(arr[i] == 'L'){
                i++;
                ptr = tail;
                ptr->next = newNode;
                newNode->data = toInt(arr[i]);
                newNode->prev = tail;
                newNode->next = NULL;
                tail = newNode;
            }
        }
        else if(arr[i] == 'D'){
            i++;
            if(arr[i] == 'F'){
                ptr = head->next;
                head->next = NULL;
                ptr->prev = NULL;
                free(head);
                head = ptr;
            }
            else if(arr[i] == 'A'){
                i++;
                ptr = head;
                for(j=0 ; j<toInt(arr[i]) ; j++){
                    if(ptr==NULL){
                        break;
                    }
                    else{
                        ptr = ptr->next;
                    }
                }
                if(ptr!=NULL){
                    if(ptr->prev == NULL){
                        head = ptr->next;
                    }
                    else{
                        ptr->prev->next = ptr->next;
                    }

                    if(ptr->next == NULL){
                        tail = ptr->prev;
                    }
                    else{
                        ptr->next->prev = ptr->prev;
                    }

                    ptr->prev = NULL;
                    ptr->next = NULL;

                    free(ptr);
                }
            }
            else if(arr[i] == 'L'){
                ptr = tail->prev;
                tail->prev = NULL;
                ptr->next = NULL;
                free(tail);
                tail = ptr;
            }
        }
        else if(arr[i] == 'P'){
            ptr = head;
            while (ptr != NULL) {
                printf("%d", ptr->data);
                ptr = ptr->next;
            }
            printf("\n\n");
        }
        else if(arr[i] == 'R'){
            ptr = tail;
            while (ptr != NULL) {
                printf("%d", ptr->data);
                ptr = ptr->prev;
            }
            printf("\n\n");
        }
        else if(arr[i] == 'S'){
            i++;
            ptr = head;
            for(j=1 ; ptr != tail ; j++){
                if(toInt(arr[i]) == ptr->data){
                    printf("%d",j);
                    j = 0;
                    break;
                }
                else{
                    ptr = ptr->next;
                }
                
            }
            if(j != 0){
                printf("-1");
            }
        }
    }
}