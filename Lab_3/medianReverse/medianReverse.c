#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

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
            if(tmp < arr[j]){
                tmp = arr[j];
                index = j;
            }
        }
        arr[index] = arr[i];
        arr[i] = tmp;
        printf("%d ",arr[i]);
    }
    printf("%d \n",arr[i]);

    double index_Median = (n-1)/2.0;
    Median = ( arr[(int)ceil(index_Median)] + arr[(int)floor(index_Median)]) / 2.0;

    printf("Median=%d",Median);
}