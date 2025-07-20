#include <stdio.h>
#include <string.h>

typedef struct{
    char id[10];
    int score;
}test;

int main(){
    int n,i,j,avr=0,count=0;

    scanf("%d",&n);

    test tmp[n],tmp1;

    for(j=0 ; j<n ; j++){
        scanf("%s %d", tmp1.id, &tmp1.score);
        tmp[j] = tmp1;
        avr+=tmp1.score;
    }

    avr/=n;

    for(i=0 ; i<2 ; i++){
        for(j=0 ; j<n ; j++){
            if(tmp[j].score>avr){
                if(i==0)
                    count++;
                else
                    printf("%s\n",tmp[j].id);
            }
        }
        if(i==0)
            printf("%d\n",count);
    }
}
