#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool pala(int n);
bool prime(int n);

int main()
{
    int n,i,min,max;

    scanf("%d",&n);

    if(pala(n) && prime(n)){
        printf("%d",n);
    }
    else{
        for(min=n-1 ; min>=2 ; min--){
            if(pala(min) && prime(min)){
                break;
            }
        }

        for(max=n+1 ; max<=100000000 ; max++){
            if(pala(max) && prime(max)){
                break;
            }
        }

        if(max-n < n-min)
            printf("%d",max);
        else
            printf("%d",min);
    }
}

bool pala(int n)
{
    int tmp=n,count=0,arr[10],i;

    while(tmp>=1){
        arr[count] = tmp%10;
        count++;
        tmp/=10;
    }

    for(i=1 ; i<=ceil(count/2.0) ; i++){
        if(arr[i-1] != arr[count-i])
            return false;
    }

    return true;
}

bool prime(int n)
{
    int i=3;

    if(n==1 || n%2==0){
        return false;
    }
    else{
        while (i*i<=n) {
            if(n%i==0 && n != i){
                return false;
           }
           i+=1;
        }
    }
    return true;
}
