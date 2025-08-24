#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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

    int arr[10][20] = {-1}, max=0, j, k, unit=0, tmp;

    for(i=0 ; i < n ; i++){
        if(num[i] > max)
            max = num[i];
    }

    for(i=0 ; i<5 ; i++){
        if(max%10 || max==10){
            unit++;
            max/=10;
        }
    }


    for(i=1 ; i<=unit ; i++){
        for(j=0 ; j<n ; j++){
            tmp = num[i] % pow(10,i);
            for(k=0 ; k<=20 ; k++){
                if(num[tmp][k] != -1){
                    num[tmp][k] = num[i];
                }
            }
        }
    }
    printf("%d",unit);
}