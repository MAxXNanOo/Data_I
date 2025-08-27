#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node *Top = NULL;

int main()
{
    char arr[50];
    scanf("%s",&arr);


    for(int i=0 ; arr[i] != '\0'; i++){
        switch(arr[i])
        {
            case '(':
            case '[':
            case '{':{
                struct node *ptr;
                ptr = (struct node *)malloc(sizeof(struct node));
                ptr->data = arr[i];
                ptr->next = Top;
                Top = ptr;
            }
            break;



            case ')':
                if(Top)
                    if(Top->data == '('){
                        Top = Top->next;
                    }
                    else{
                    printf("-1");
                    return -1;
                }
                else{
                    printf("-1");
                    return -1;
                }

            break;
            case ']':
                if(Top)
                    if(Top->data == '['){
                        Top = Top->next;
                    }
                    else{
                    printf("-1");
                    return -1;
                }
                else{
                    printf("-1");
                    return -1;
                }

            break;
            case '}':
                if(Top)
                    if(Top->data == '{'){
                        Top = Top->next;
                    }
                    else{
                    printf("-1");
                    return -1;
                }
                else{
                    printf("-1");
                    return -1;
                }

            break;
        }
    }
    if(Top){
        printf("-1");
    }
    else{
        printf("0");
    }



//    printf("\n%s",arr);
}
