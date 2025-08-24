#include <stdio.h>
#define maxSize 10
int main()
{
    char input[50],ch,arr[10];
    int numCh, Front = -1, Rear = -1, size = 0;
    scanf("%s",input);

    for(int i=0 ; input[i] != '\0' ; i++){
        ch = input[i];
        numCh = (int)ch - 48;

        if(numCh == 0){
            printf("%d%d",Front,Rear);
        }
        else if(numCh >= 1 && numCh <=9){
            for(int j=0 ; j<numCh ; j++){
                if(size){
                    size--;
                    printf("%c",arr[Front]);
                    Front = (Front + 1) % maxSize;
                }
                else{
                    printf("!");
                }
            }
        }
        else{
            if(Front == -1)
                Front++;
            if(size < maxSize){
                Rear = (Rear + 1) % maxSize;
                arr[Rear] = ch;
                size++;
            }
            else{
                printf("!");
            }
            
            // printf("%c %d  /  ",arr[Rear],numCh);
        }
    }

    // for(int i=0 ; i<10 ; i++){
    //     printf("%c",arr[i]);
    // }
}