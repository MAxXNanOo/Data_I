#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct node {
    char data;
    struct node *next;
};


struct node *Top = NULL;


int main()
{
    char cmd[10], tmpCmd[1000][10],tmpWord[1000], ch;
    int sizeCmd=-1;

    while(1){
        scanf("%s",&cmd);
        // printf("cmd = %s \n",cmd);
        if(!strcmp(cmd, "WRITE")){
            // printf("Write : ");
            scanf("%s",&ch);

            tmpWord[sizeCmd] = ch;

            struct node *new = (struct node *)malloc(sizeof(struct node));
            new->data = ch;
            new->next = Top;
            Top = new;

            // printf("--%s\n",tmpCmd[0]);
        }
        else if(!strcmp(cmd, "UNDO")){
            // printf("--UNDO ");
                if(Top){
                    
                    strcpy(tmpCmd[++sizeCmd], cmd);
                    tmpWord[sizeCmd] = Top->data;
                    Top = Top->next;
                }

        }
        else if(!strcmp(cmd, "READ")){
            if(Top)
            {    struct node *ptr = Top,*preptr = NULL;
                do{
                    ptr = Top;
                    while(ptr->next != preptr){
                        ptr = ptr->next;
                    }
                    preptr = ptr;

                    printf("%c",ptr->data);
                }while(ptr != Top);
            }
            else{
                printf("Blank document");
            }

            printf("\n");
        }
        else if(!strcmp(cmd, "REDO")){
            if(sizeCmd != -1){
                struct node *new = (struct node *)malloc(sizeof(struct node));
                new->data = tmpWord[sizeCmd];
                new->next = Top;
                Top = new;
            }
        }
        else if(!strcmp(cmd, "END")){
            break;
        }
    }
}
