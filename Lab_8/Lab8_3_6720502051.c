#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};

int Index=-1 ;
char input[50];
struct Treenode *Root;

struct Treenode *createNode(char);
void SetLeft(struct Treenode *, char);
void SetRight(struct Treenode *, char);
void preorder(struct Treenode *);
void postorder(struct Treenode *);
void makeTree(struct Treenode *);
bool checkMath(char);




int main()
{
    

    scanf("%s", &input);
    
    Root = createNode(input[0]);

    // for(int i=1 ; input[i]!='\0' ; i++){
    //     char ch = input[i];

    // }
    struct Treenode *node = Root;
    makeTree(node);

    postorder(Root);
}



bool checkMath(char ch){
    if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
        return true;
    else
        return false;
}
bool checkNotMath(char ch){
    if(ch != '+' && ch != '-' && ch != '*' && ch != '/')
        return true;
    else
        return false;
}

void makeTree(struct Treenode *ptr){

    while(ptr->leftChild && ptr->rightChild){
        char ch = input[++Index]; 

        if( checkMath(ch) || (!ptr->leftChild && checkNotMath(ch))){
            SetLeft(ptr, ch);
            makeTree(ptr->leftChild);
        }
        else{
            SetRight(ptr, ch);
            makeTree(ptr->rightChild);
        }
    }

}




struct Treenode *createNode(char data)
{
    struct Treenode *new_node = (struct Treenode *)malloc(sizeof(struct Treenode));
    new_node->data = data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;

    return new_node;
}




void SetLeft(struct Treenode *ptr, char data)
{
    ptr->leftChild = createNode(data);
}




void SetRight(struct Treenode *ptr, char data)
{
    ptr->rightChild = createNode(data);
}




void preorder(struct Treenode *ptr)
{
    if (ptr)
    {
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}




void postorder(struct Treenode * ptr){

    if(ptr){
        
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);

        // if(!ptr->leftChild && !ptr->rightChild){
            printf("%c",ptr->data);
            // free(ptr);
        // }
    }
}