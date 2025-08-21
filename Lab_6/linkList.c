#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *Front=NULL ,*Rear=NULL;

void enqueue(int);
int dequeue();
void displayQ();

int main()
{
    int i,n;
    for(i=1; i<1000; i*=2)
        enqueue(i);
    displayQ();
    scanf("%d",&n);
    for(i=1; i<=n; i++)
        dequeue();
    displayQ();
    for(i=10; i>=1; i/=2)
        enqueue(i);
    displayQ();
}

void enqueue(int data)
{
        struct node *new_node = (struct node *)malloc(sizeof(struct node));
        new_node->data = data;
        if(Front){
           Rear->next = new_node;
            Rear = new_node;
        }
        else{
            Front = new_node;
            Rear = new_node;
        }

}

int dequeue()
{
    int data;
    if(!Front){
        printf("\nQueue is Empty\n");
        return -1;
    }
    else{
        //Q[Front]=0;

        struct node *ptr = Front;
        Front = Front->next;
        ptr->next = NULL;
        free(ptr);
        return 1;
    }
}

void displayQ()
{
    int i;
    if(!Front){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("front[");
        struct node *ptr = Front;
        do{
            printf("%d ",ptr->data);
            if(ptr == Rear)
                break;
            ptr = ptr->next;
        }while(1);
        printf("]rear\n");
    }
}
