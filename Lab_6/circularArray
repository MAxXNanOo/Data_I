#include <stdio.h>
#define maxsize  10
int Q[maxsize]= {0};
int Front=-1, Rear=-1;
int size=0;

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
    if(size==maxsize){
        printf("\nQueue is Full\n");
    }
    else{
        Rear++;
        Rear %= maxsize;
        Q[Rear] = data;
        if(Front == -1){
            Front = 0;
        }
        size++;
    }
}

int dequeue()
{
    int data;
    if(size == 0){
        printf("\nQueue is Empty\n");
        return -1;
    }
    else{
        //Q[Front]=0;
        Front++;
        Front %= maxsize;
        size--;
        return 1;
    }
}

void displayQ()
{
    int i;
    if(size == 0){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("front[");
        for(i=Front ; i<size+Front ; i++){
            printf("%d ",Q[i%maxsize]);
        }
        printf("]rear\n");
    }
}
