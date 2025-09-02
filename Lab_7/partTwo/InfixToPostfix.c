#include <stdio.h>

int main(){
    char arr[50],inputArr[50],ans[50];
    int Top = -1,ansTop = -1;

    scanf("%s",&inputArr);

    for(int i=0 ; inputArr[i]!='\0' ; i++){
        switch(inputArr[i]){
            case '(':
                arr[++Top] = inputArr[i];
            break;

            case ')':
                while(arr[Top] != '('){
                    ans[++ansTop] = arr[Top--];
                    // printf("%c",arr[Top--]);
                }
                Top--;
            break;

            case '^':
                arr[++Top] = inputArr[i];
            break;

            case '*':
            case '/':
                while(arr[Top] == '^'){
                    ans[++ansTop] = arr[Top--];
                    // printf(" %c ",ans[ansTop]);
                }
                arr[++Top] = inputArr[i];
            break;

            case '+':
            case '-':
                while(arr[Top] == '^' || arr[Top] == '*' || arr[Top] == '/' ){
                    ans[++ansTop] = arr[Top--];
                    // printf(" %c ",ans[ansTop]);
                }
                arr[++Top] = inputArr[i];
            break;
            
            default:
                ansTop++;
                ans[ansTop] = inputArr[i];
                // printf("%c",ans[ansTop]);
        }
    }

    while(Top != -1){
        ans[++ansTop] = arr[Top--];
    }

    for(int i=0 ; i<=ansTop ; i++){
        printf("%c",ans[i]);        
    }

    // printf("arr = %s",inputArr);
}