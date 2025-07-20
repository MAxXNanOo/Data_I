#include <stdio.h>
#include <stdbool.h>

bool prime(int n)
{
    int i=3;

    if(n==1 || n%2==0 && n!=2){
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

int main()
{
    int n,min,max,i;

    scanf("%d",&n);

    if(prime(n)){
        printf("%d",n);
    }
    else{
        for(min=n-1 ; min>=2 ; min--){
            if(prime(min)){
                break;
            }
        }
        for(max=n+1 ; ; max++){
            if(prime(max)){
                break;
            }
        }

        if(max - n < n - min){
            printf("%d",max);
        }
        else{
            printf("%d",min);
        }
}
