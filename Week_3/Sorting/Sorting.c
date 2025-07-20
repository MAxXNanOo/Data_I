#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10
int numCompare=0,numSwap=0;

// Display all element in array
void DisplayArray(int A[], int n)
{
    int i;

    for (i=0; i< n; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void SelectionSort(int A[], int n)
{
    int i,j,tmp,index;
    for(i=0 ; i<n-1 ; i++){
        tmp = A[i];
        index=i;
        for(j=i+1 ; j<n ; j++){
            numCompare++;
            if(tmp > A[j]){
                numSwap++;
                tmp = A[j];
                index = j;
            }
        }
        A[index] = A[i];
        A[i] = tmp;
    }
}

void InsertionSort(int A[], int n)
{
    int i,j,tmp;
    bool Loop;
    for(i=0 ; i<n ; i++){
        Loop = true;
        for(j=i ; j>0 ; j--){
            numCompare++;
            if(A[j] < A[j-1]){
                numSwap++;
                tmp = A[j];
                A[j] = A[j-1];
                A[j-1] = tmp;
                Loop = false;
            }
        }
    }
}

void BubbleSort(int A[], int n)
{
    bool swapped;
    int i,j,tmp;
    for(i = 0; i < n - 1; i++) {
        swapped = false;
        for(j = 0; j < n - i - 1; j++) {
            numCompare++;
            if(A[j] > A[j+1]) {
                numSwap++;
                tmp = A[j];
                A[j] = A[j+1];
                A[j+1] = tmp;
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
}





int main()
{
    int A[MAX]/* = {15 ,30 ,2 ,1 ,3 ,29 ,27 ,20 ,22 ,16 }*/;
    int i;

    srand(time(NULL));

    //for(i=0 ; i<MAX ; i++)
    //    A[i] = i+1;
    for(i=0 ; i<MAX ; i++){
        A[i] = 10-i;
    }
        
    //for (i=0; i< MAX; i++){
    //    A[i] = rand()%30 +1;
    //} 
    
    DisplayArray(A, MAX);
    InsertionSort(A, MAX);              //Call Sorting Function
    DisplayArray(A, MAX);

    printf("\n\n Com : %d   Swap : %d ",numCompare,numSwap);
    return 0;


}