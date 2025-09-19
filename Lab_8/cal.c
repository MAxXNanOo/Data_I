#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

struct Treenode *Root = NULL;
struct Treenode *TreeArr[50];
int TreeTop = -1;

int toInt(char data){
    return data-48;
}

void depo(struct Treenode * ptr){
    if(ptr){
        if(ptr->data == '+' || ptr->data == '-' || ptr->data == '*' || ptr->data == '/'){
            printf("(");
            depo(ptr->leftChild);
            printf("%c", ptr->data);
            depo(ptr->rightChild);
            printf(")");
        }
        else{
            depo(ptr->leftChild);
            printf("%c", ptr->data);
            depo(ptr->rightChild);
        }
        
    }
}


int main()
{
    char input[50], ch;
    int size = 0, top = -1, num[50], sum;
    scanf("%s",&input);

      
    for(size=0 ; input[size]!='\0' ; size++);

    // printf("size = %d\n",size);
    for(size-- ; size>=0 ; size--){
        ch = input[size];
        if(0 <= toInt(ch) && toInt(ch) <=9){
            struct Treenode *new = (struct Treenode *)malloc(sizeof(struct Treenode));
            new->data = ch;
            new->leftChild = NULL;
            new->rightChild = NULL;
            TreeArr[++TreeTop] = new;
        }
        else{
            struct Treenode *new = (struct Treenode *)malloc(sizeof(struct Treenode));
            struct Treenode *left, *right;
            left = TreeArr[TreeTop--];
            right = TreeArr[TreeTop--];

            new->data = ch;
            new->leftChild = left;
            new->rightChild = right;
            TreeArr[++TreeTop] = new;
        }
            // printf("%d ",toInt(ch));


        switch(input[size]){
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

                default :
                    num[++top] = toInt(input[size]);
                    printf("put %d\n",num[top]);
        }
    }



    depo(TreeArr[0]);
    printf("=%d",num[0]);

}

