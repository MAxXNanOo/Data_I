#include <stdio.h>

int main()
{
    int N,K,number;

    scanf("%d %d",&N,&K);

    int Front = 0, Rear = N-1, Q[N];

    for(int i=Front ; i<=Rear ; i++){
        scanf("%d",&Q[i]);
    }

    int tmp = Front, pretmp = K + Front -1 , supertmp;

    for(tmp, pretmp ; tmp < pretmp ; tmp++, pretmp--){
        supertmp = Q[tmp];
        Q[tmp] = Q[pretmp];
        Q[pretmp] = supertmp;
    }

    for(int i=Front ; i<=Rear ; i++){
        printf("%d ",Q[i]);
    }
}