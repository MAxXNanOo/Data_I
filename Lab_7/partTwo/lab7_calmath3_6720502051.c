#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

struct node
{
    char ch;
    int data;
    struct node *next;
};

struct node *head = NULL;

int main()
{
    char arr[50],inputArr[50],ans[50];
    int Top = -1,ansTop = -1;

    printf("Enter infix:");
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
                while(arr[Top] == '^' || arr[Top] == '*' || arr[Top] == '/'){
                    ans[++ansTop] = arr[Top--];
                    // printf(" %c ",ans[ansTop]);
                }
                arr[++Top] = inputArr[i];
            break;

            case '+':
            case '-':
                while(arr[Top] == '^' || arr[Top] == '*' || arr[Top] == '/' || arr[Top] == '+' || arr[Top] == '-' ){
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

    ans[ansTop + 1] = '\0';

    printf("Postfix:");
    for(int i=0 ; ans[i]!='\0' ; i++){
        printf("%c",ans[i]);
    }
    printf("\n");

    int num[50];
    int numTop = -1;

    for(int i=0 ; ans[i]!='\0' ; i++){
        if(ans[i] == '+' || ans[i] == '-' || ans[i] == '*' || ans[i] == '/' || ans[i] == '^'){

            switch(ans[i]){
                case '+':
                    //printf("%d run %d + %d = %d",numTop,num[numTop-1],num[numTop],num[numTop-1]+num[numTop]);
                    num[numTop-1] = num[numTop-1] + num[numTop ];
                break;

                case '-':
                    num[numTop-1] = num[numTop-1] - num[numTop ];
                break;

                case '*':
                    num[numTop-1] = num[numTop-1] * num[numTop ];
                break;

                case '/':
                    num[numTop-1] = num[numTop-1] / num[numTop ];
                break;

                case '^':
                    num[numTop-1] = pow(num[numTop-1] , num[numTop ]);
                break;
            }
            numTop--;
        }
        else{

            struct node *ptr = head;
            int check = 0;
            numTop++;
            while(ptr){
                if(ans[i] == ptr->ch){
                    num[numTop] = ptr->data;
                    check = 1;
                }

                ptr = ptr->next;
            }

            if(check == 0){
                struct node *new_node = (struct node *)malloc(sizeof(struct node));
                new_node->ch = ans[i];
                printf("Enter value of %c : ",ans[i]);
                int tmp;
                scanf("%d",&tmp);
                new_node->data = tmp;
                new_node->next = head;
                head = new_node;

                num[numTop] = new_node->data;
                printf("end");
            }
//            numTop++;
//            printf("Enter value of %c : ",ans[i]);
 //           scanf("%d",&num[numTop]);
            //num[numTop] = (int)ans[i]-48;
        }
    }

    printf("\nResult= %d",num[0]);
}
