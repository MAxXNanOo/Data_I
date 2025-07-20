#include <stdio.h>
#include <stdbool.h>

int main()
{
    int n,w,i,j,tmp;
    scanf("%d %d",&n,&w);

    int arr[n],weight=0;
    bool Loop = true;
    
    for(i=0 ; i<n ; i++){
        scanf("%d",&arr[i]);
    }

    for(i = 0; i < n - 1; i++) {
    bool swapped = false;
    for(j = 0; j < n - i - 1; j++) {
        if(arr[j] > arr[j+1]) {
            tmp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = tmp;
            swapped = true;
        }
    }
    if(!swapped)
        break;
}


    for(i=0 ; i<n && weight+arr[i]<=w ; i++){
        if(weight+arr[i]<=w)
            weight+=arr[i];
    }

    printf("%d",i);
}