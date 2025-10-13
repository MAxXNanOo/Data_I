#include <stdio.h>
#define maxsize 10
char Q[maxsize];
int Font = -1, Rear = -1;
int size = 0;

int main()
{
    char input[100];
    scanf("%s", &input);

    int number;

    for(int i=0 ; input[i] != '\0' ; i++){
        if('A' <= input[i] && input[i] <= 'Z'){
            if(size < maxsize){
                if(Font == -1)
                    Font++;
                Rear = (Rear+1)%10;
                Q[Rear] = input[i];
                size++;
            }
            else{
                printf("!");
            }
        }
        else if('1' <=input[i] && input[i] <= '9'){
            number = input[i] - '0';
            for(int j=0 ; j<number ; j++){
                if(size>0){
                    printf("%c",Q[Font]);
                    Font = (Font+1)%10;
                    size--;
                }
                else{
                    printf("!");
                }
            }
        }
        else if(input[i] == '0'){
            printf("%d%d",Font,Rear);
        }
    }
}