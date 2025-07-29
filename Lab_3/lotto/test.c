#include <stdio.h>
#include <stdbool.h>
#define MAX 10
#include <time.h>
#include <stdlib.h>
int numCompare =0,numSwap=0;

void swap(int *X,int *Y)
{
     int temp = *X;
     *X = *Y;
     *Y = temp;
     numSwap++;
      
}
void DisplayArray(int A[], int n)
{
    int i;

    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void SelectionSort(int A[], int n)
{
    for (int i = 0;i <= n-2;i++)
    {
        numCompare++;
        int min = i;
        for(int j = i +1;j <= n-1;j++)
        {
            numCompare++;
            if (A[j] < A[min])
                min = j;
                
        }
       
        swap(&A[i],&A[min]);
        
      
    }
}

void InsertionSort(int A[], int n)
{
    for(int i = 1;i <=n-1;i++)
    {
        numCompare++;
        int j= i;
        while(j>0 && A[j]<A[j-1])
        {
            numCompare++;
            swap(&A[j],&A[j-1]);
            j--;
        }
    }
}

void BubbleSort(int A[], int n)
{
       for (int i = 0; i < n - 1; i++) {
        numCompare++;
        for (int j = 0; j < n - i - 1; j++) {
        numCompare++;
            if (A[j] > A[j + 1]) {
                swap(&A[j], &A[j + 1]);
            }
        }
    }
       
            
}


int main()
{
    int A[MAX];
     int i,j;

    /*for (i=0; i< MAX; i++)
    {
        A[i] = i+1;
    }*/
    /*for (i=0; i< MAX; i++)
    {
        A[i] = 10-i;
    }*/
    srand(time(NULL));
    /*for (i=0; i< MAX; i++)
    {
        A[i] = rand()%30 +1;
    }*/
    A[0] = 13;
    A[1] = 26;
    A[2] = 5;
    A[3] = 9;
    A[4] = 11;
    A[5] = 11;
    A[6] = 30;
    A[7] = 31;
    A[8] = 17;
    A[9] = 1;
    DisplayArray(A, MAX);
    SelectionSort(A, MAX); 
    //InsertionSort(A,MAX);
    //BubbleSort(A,MAX);
    DisplayArray(A, MAX);
    printf("numCom = %d\n",numCompare);
    printf("numSwap = %d",numSwap);
    return 0;
}