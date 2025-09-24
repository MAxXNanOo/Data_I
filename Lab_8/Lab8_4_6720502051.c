#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


struct Treenode {
    char data[100];
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

struct Treenode *TreeArr[100];
int TreeTop = -1;

int toInt(char ch[100])
{

    int len, Index, sum=0;

    for(len=strlen(ch)-1, Index=0; len>=0 ; len--,Index++){
        sum += (int)(ch[Index]-48)*pow(10, len);
    }
    return sum;

}

void depo(struct Treenode *ptr)
{
    if(ptr){
        if(!strcmp(ptr->data, "+") || !strcmp(ptr->data, "-") || !strcmp(ptr->data, "*") || !strcmp(ptr->data, "/") || !strcmp(ptr->data, "^")){
            printf("(");
            depo(ptr->leftChild);
            printf("%s",ptr->data);
            depo(ptr->rightChild);
            printf(")");
        }
        else{
            depo(ptr->leftChild);
            printf("%s",ptr->data);
            depo(ptr->rightChild);        
        }
    }
}

int main()
{
    char input[100];
    char arr[100][100];
    int inputSize = -1, arrSize = -1, num[100], top=-1;
    long int sum = 0;
    int i=0,k=0;

    scanf("%[^\n]s", &input);

    // printf("%s\n\n",input);

    for(inputSize=0, arrSize=0, i=0 ; input[inputSize]!='\0' ; inputSize++){
        if(input[inputSize] == ' '){
            
            i=0;
            arrSize++;
            continue;
        }
        else{
            // printf("put %c [%d][%d]",input[inputSize], input);
            arr[arrSize][i] = input[inputSize];
            i++;
            arr[arrSize][i] = '\0';
        }

    }

    for(i=0 ; i<=arrSize ; i++){
        // printf("%s ", arr[i]);

        struct Treenode *new = (struct Treenode *)malloc(sizeof(struct Treenode));
        strcpy(new->data, arr[i]);

        if(!strcmp(new->data, "+") || !strcmp(new->data, "-") || !strcmp(new->data, "*") || !strcmp(new->data, "/") || !strcmp(new->data, "^")){
            new->rightChild = TreeArr[TreeTop--];
            new->leftChild = TreeArr[TreeTop--];
        }
        else{
            printf("i=%d  ",i);
            new->leftChild = NULL;
            new->rightChild = NULL;
        }

        TreeArr[++TreeTop] = new;




        switch(arr[i][0]){
            case '+':
                num[top-1] = num[top-1] + num[top];
                top--;
            break;

            case '-':
                num[top-1] = num[top-1] - num[top];
                top--;
            break;

            case '*':
                num[top-1] = num[top-1] * num[top];
                top--;
            break;

            case '/':
                num[top-1] = num[top-1] / num[top];
                top--;
            break;

            case '^':
                num[top-1] = pow(num[top-1] , num[top ]);
                top--;
            break;

            default:
                num[++top] = toInt(arr[i]);
        }
    }

    depo(TreeArr[0]);
    printf(" = %d",num[0]);

    // for(size ; 1 ; size++){
    //     if(input[] != ''){
    //         printf("put len = %d\n",strlen(input));
    //         TreeArr[size] = (struct Treenode *)malloc(sizeof(struct Treenode));
    //         strcpy(TreeArr[size]->data, input);
    //         TreeArr[size]->leftChild = NULL;
    //         TreeArr[size]->rightChild = NULL;
    //     }
    //     else if(input[size] == )
    //     else{
    //         break;
    //     }
    // }

    // for(int i=0 ; i<size ; i++){
    //     printf("%s ",TreeArr[i]->data);
    // }
}