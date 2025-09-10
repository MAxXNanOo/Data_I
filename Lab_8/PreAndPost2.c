#include <stdio.h>
#include <stdlib.h>

struct Treenode
{
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
};
struct Treenode *Root = NULL;

struct Treenode *createNode(char);
void SetLeft(struct Treenode *, char);
void SetRight(struct Treenode *, char);
void preorder(struct Treenode *);
void postorder(struct Treenode *);

int main()
{
    struct Treenode *pn, *tnode;

    // create Exptree for Lab8
    // create root node
    tnode = createNode('+');
    if (Root == NULL)
        Root = tnode;

    // create node level 1
    SetLeft(Root, '*');
    SetRight(Root, 'E');

    // create node level 2
    pn = Root->leftChild;
    SetLeft(pn, '*');
    SetRight(pn, 'D');

    // create node level 3
    pn = pn->leftChild;
    SetLeft(pn, '/');
    SetRight(pn, 'C');

    // create node level 4
    pn = pn->leftChild;
    SetLeft(pn, 'A');
    SetRight(pn, 'B');

    // call preorder and postorder
    printf("Prefix: ");
    preorder(Root);
    printf("\nPostfix: ");
    postorder(Root);

    free(tnode);
    free(pn);
    return 0;
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