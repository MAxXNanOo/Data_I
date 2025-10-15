#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int heap[100];

int main()
{
    int n,index,par,tmp;
    scanf("%d", &n);



    for(int i=0 ; i<n ; i++){
        scanf("%d", &heap[i]);

        index = i;
        while( index >= 0 ){
            par = (index-1)/2;
            if(heap[index] < heap[par]){
                tmp = heap[index];
                heap[index] = heap[par];
                heap[par] = tmp;
            }
            else{
                index--;
            }
        }
    }


    printf("\n");
    int j=1;
    for(int i=0 ; i<n ; i++){
        if(i == pow(2,j) - 1){
            printf("\n");
            j++;
        }
        printf("%d ", heap[i]);
    }



}