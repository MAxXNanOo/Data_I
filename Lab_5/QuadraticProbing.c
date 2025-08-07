#include <stdio.h>
#define HTsize 10
int hashArray[HTsize]= {0}; //hash table
int h(int k) //for generate hash function
{
    return k%HTsize;
}
void setHash(int n) //for insert number in hash table
{
    int index,check=1;
    index=h(n); //call genHashFn

    printf("%d mod 10 = %d\n",n,index);
    for(int i=0 ; i<10 ; i++)
    {
        if(hashArray[(index+i*i)%10] == n)
        {
            printf("Duplicate number!\n");
            check=0;
            break;
        }
        else if(hashArray[(index+i*i)%10] == 0)
        {
            hashArray[(index+i*i)%10] = n;
            printf("  Put %d in H[%d]\n",n,index+i*i);
            check=0;
            break;
        }
        else
        {
            printf(" (%d+%d)mod 10 == %d\n",index,(i+1)*(i+1),(index+(i+1)*(i+1))%10);
        }
    }
    if(check){
        printf("Hash Table is full!\n");
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
