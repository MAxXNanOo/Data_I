#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 20
int Q[10][20];
int Front=-1,Rare=-1;
int size=0;
void enqueue(int a,int b){
    if(size==maxsize){
        printf("FULL");
    }
    else{
        if(size==0){
            Front=0;Rare=0;
        }
        else
            Rare++;
            size++;
    }
    Q[Rare]=a;
}
int dequeue(){
    if(size==0)
        printf("Emthy");
    else{

    }
}
int main(){
    int i,n=20;
    srand((unsigned) time(NULL));
    int num[n];
    printf("Number before sorting\n");
    for(i=0;i<n;i++){
        num[i]=rand();
        printf("%d\n",num[i]);
        while(num[i]>0){
            printf("-%d-",num[i]%10);
            num[i]=num[i]/10;
        }
         printf("*\n");
    }

}