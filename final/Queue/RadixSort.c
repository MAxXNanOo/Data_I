#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

int main()
{
    int i,n=20;
    srand((unsigned)time(NULL));
    int num[n];

    printf("Nummber before sorting\n");
    for(i=0 ; i<n ; i++){
        num[i] = rand() % 32768;
        printf("%d ", num[i]);
    }

    int rd[10][20];
    int count =0;
    int top;

    for(i=0 ; i<=5 ; i++){
        for(int j=0 ; j<10 ; j++){
            for(int k=0 ; k<20 ; k++){
                rd[j][k] = -1;
            }
        }

        for(int j=0 ; j<20 ; j++){
            count = 0;
            while(rd[((int)num[j]/pow(10,i)) % 10][count] != -1)
                count++;
            rd[(int)(num[j]/pow(10,i)) % 10][count] = num[j];
        }

        top=0;
        for(int j=0 ; j<10 ; j++){
            count = 0;
    
            while(rd[j][count] != -1){
                num[top++] = rd[j][count];
            }
        }
    }

    printf("\n\n");

    for(i=0 ; i<n ; i++){
        printf("%d ", num[i]);
    }
}