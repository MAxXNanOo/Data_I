#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int main()
{
    int i, n = 20;
    srand((unsigned)time(NULL)); // Initializes random number generator
    int num[n];
    printf("Number before sorting\n");
    for (i = 0; i < n; i++)
    {
        num[i] = rand(); // random number between 0-32767
        printf("%d ", num[i]);
    }


    // Fill C O D E

    int arr[10][20] = {}, max=0, j, k, unit=0, tmp, check=0, Index;

    for(i=0 ; i < n ; i++){
        if(num[i] > max)
            max = num[i];
    }
    // printf("\nMax = %d \n",max);
    while(max != 0){
        unit++;
        max/=10;
    }
    

    // printf("\nUnit = %d\n",unit);
    for(i=1 ; i<=unit ; i++){
        
        for(j=0 ; j<n ; j++){
            k = 0;
            Index = (num[j] / (int)(pow(10, i))) % 10;
            do{
                if(arr[Index][k] == 0){
                    // printf("arr[%d][%d] = %d\n",Index,k,num[j]);
                    arr[Index][k] = num[j];
                    num[j] = 0;
                    break;
                }
                else{
                    k++;
                }
            }while(191);
        }
        //  printf("\n\n");
        for(Index=0, j=0; Index<10 ; Index++){
            k = 0;
            while(arr[Index][k] != 0){
                // printf("INPUT %d/%d  \n",Index,arr[Index][k]);
                num[j] = arr[Index][k];
                arr[Index][k] = 0;
                j++;
                k++;
            }
        }
        
        // printf("\n i = %d \n",i);
    }
    
    printf("\n\n");
    for(i=0 ; i<n ; i++){
        printf("%d ",num[i]);
    }
}