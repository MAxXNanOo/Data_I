#include <stdio.h>
#include <math.h>

int main()
{
    int n,sum=0,i;

    printf("Code run");
    scanf("%d",&n);

    for(i=0 ; i<9 ; i++){
        if(9*pow(10,i) < n){
            sum += 9*pow(10,i)*(i+1);
            n -= 9*pow(10,i);
        }
        else{
            sum += n*(i+1);
            break;
        }
    }

    printf("%d",sum);
}
