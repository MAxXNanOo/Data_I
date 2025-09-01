#include <stdio.h>
#include <stdlib.h>

struct node{
    char data;
    struct node *next;
};

struct node *Top = NULL;
int size=0;

int main()
{
    char arr[50];
    scanf("%s",&arr);

    int i;
    for(i=0 ; arr[i] != '\0'; i++){
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
                size++;
            }
            break;


            case ')':
            case ']':
            case '}':{
                
                if(!Top){
                    printf("-1");
                    return -1;
                }
                switch(arr[i]){
                    case ')':
                        if(Top->data == '('){
                            Top = Top->next;
                            size--;
                            printf("D (   ");
                        }
                        else{
                            printf("-1");
                            return -1;
                        }
                    break;

                    case ']':
                        if(Top->data == '['){
                            Top = Top->next;
                            size--;
                            printf("D [   ");
                        }
                        else{
                            printf("-1");
                            return -1;
                        }
                    break;

                    case '}':
                        if(Top->data == '{'){
                            Top = Top->next;
                            size--;
                            printf("D {   ");
                        }
                        else{
                            printf("-1");
                            return -1;
                        }
                    break;
                }
            }
            break;


            // case ')':
            //     if(Top)
            //         if(Top->data == '('){
            //             Top = Top->next;
            //         }
            //         else{
            //         printf("-1");
            //         return -1;
            //     }
            //     else{
            //         printf("-1");
            //         return -1;
            //     }

            // break;
            // case ']':
            //     if(Top)
            //         if(Top->data == '['){
            //             Top = Top->next;
            //         }
            //         else{
            //         printf("-1");
            //         return -1;
            //     }
            //     else{
            //         printf("-1");
            //         return -1;
            //     }

            // break;
            // case '}':
            //     if(Top)
            //         if(Top->data == '{'){
            //             Top = Top->next;
            //         }
            //         else{
            //         printf("-1");
            //         return -1;
            //     }
            //     else{
            //         printf("-1");
            //         return -1;
            //     }

            // break;
        }

     }


    if(arr[i-1] == '\0'){
        printf("-1");
    }
    else if(Top){
        printf("Last %d",size);
    }
    else{
        printf("0");
    }

    while(Top){
        printf("%c ",Top->data);
        Top = Top->next;
    }


//    printf("\n%s",arr);
}
