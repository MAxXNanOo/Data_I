#include <stdio.h>
int main()
{
    long int N , i=2 , check=0;
    printf("Enter N : ");
    scanf("%d",&N);
    if(N == 1)
    {
        printf("%d is not a prime number",N);
    }
    else
    {
        for( ; i<N ; i++){
            if(N%i==0) {
                printf("%d is not a prime number",N);
                return 0;
            }
        }
        printf("%d is a prime number",N);
    }

}
