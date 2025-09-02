#include <stdio.h>

int main()
{
    char arr[50], sym[50];
    int numTop = -1, symTop = -1, num[50], size=0;

    scanf("%s", &arr);

    for(int i=0 ; arr[i]!='\0' ; i++){
        if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '^'){
            
        }
        else{
            num[++numTop] = (int)arr[i]-48;
        }

        size++;
    }

    for(int i=size-1 ; i>=0 ; i--){
        if(arr[i] == '+' || arr[i] == '-' || arr[i] == '*' || arr[i] == '/' || arr[i] == '^'){
            sym[++symTop] = arr[i];
        }
        else{
            
        }
    }

    for( ; numTop != 0 ; numTop--, symTop--){
        switch(sym[symTop]){
            case '+':
                num[numTop-1] = num[numTop] + num[numTop - 1];
            break;

            case '-':
                num[numTop-1] = num[numTop] - num[numTop - 1];
            break;

            case '*':
                num[numTop-1] = num[numTop] * num[numTop - 1];
            break;

            case '/':
                num[numTop-1] = num[numTop] / num[numTop - 1];
            break;
        }
    }

    printf("\n%d",num[0]);

    // while(symTop != -1){
    //     printf("%c",sym[symTop--]);
    // }
}