#include <stdio.h>
#define HTsize 10
int hashArray[HTsize]= {0}; //hash table
int h(int k) //for generate hash function
{
    return k%HTsize;
}
void setHash(int n) //for insert number in hash table
{
    int index;
    index=h(n); //call genHashFn

    printf("%d mod 10 = %d\n",n,index);
    for(int i=0 ; i<10 ; i++){
        if(hashArray[(index+i)%10] == 0){
            hashArray[(index+i)%10] = n;
            printf("  Put %d in H[%d]\n",n,index+i);
            break;
        }
        else{
            printf(" (%d+%d)mod 10 == %d\n",index,i+1,(index+i+1)%10);
        }
    }
}

int main()
{
    int n,h;

    do
    {
        printf(" Enter number:");
        scanf("%d",&n);
        if(n>=1)
            setHash(n);
    }
    while(n>=1);
//display hash table
    for (h = 0; h < HTsize; h++)
        printf("%d [%d]\n", h,hashArray[h]);

}
