#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define maxsize 20
int Q[10][20];
//int Front=-1,Rare=-1;
//int size=0;
/*void enqueue(int a,int b){
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
    Q[a][Rare]=b;
}
int dequeue(){
    int data;
    if(size==0)
        printf("Emthy");
    else{
        data=Q[Front][Rare];
        Front++;
        return data;
    }
}
void display(){
    int j=0;
    for(int i=0;i<=9;i++){
    while(Q[i][j+1]>-1)
    printf("%d ",Q[i][j]);
    break;
    j++;
    }
}*/
int main(){
    int i,n=20;
    srand((unsigned) time(NULL));
    int num[n];
    for(int i=0;i<10;i++){
    for(int j=0;j<20;j++){
        Q[i][j]=-1;
    }
}
    printf("Number before sorting\n");
    for(i=0;i<n;i++){
        num[i]=rand();
        printf("%d ",num[i]);
    }
     printf("\n",num[i]);
    for(i=0;i<n;i++){
        int c=4,ns=0;
        while(Q[num[i]%10][ns]!=-1){
            ns++;
        }
         Q[num[i]%10][ns]=num[i];
        }
        for(int i=0;i<10;i++){
            int j=0;
        while( Q[i][j]!=-1){
        printf("%d ",Q[i][j]);
         j++;
    }
}
}