#include <stdio.h>
#define maxsize 100

int Q[maxsize]; 
int font = -1, rear = -1;

int main()
{
    int N,K;
    scanf("%d", &N);
    scanf("%d", &K);

    font++;
    for(int i=0 ; i<N ; i++){
        scanf("%d", &Q[++rear]);
    }

    for(int i=K-1 ; i>=font ; i--){
        printf("%d ", Q[i]);
    }

    font+=K;

    for( ; font<=rear ; font++){
        printf("%d ", Q[font]);
    }
}