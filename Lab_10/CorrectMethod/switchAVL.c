#include <stdio.h>
#include <stdlib.h>

struct avl{
    int data;
    int ht;
    struct avl *leftChild;
    struct avl *rightChild;
}

struct avl *Root;

struct avl *creatNode (int data){
    struct avl *newNode;
    newNode->data = data;
    newNode->ht = 0;
    newNode->leftChild = NULL;
    newNode->rightChild = NULL;
    return newNode;
}


int Height(struct avl *node){
    if(node){
        return node->ht;
    }
    else{
        return 1;
    }
}


int setHeight(struct avl *node){
  if(node){
    node->ht = 1 + fmax(setHeight(node->leftChild), setHeight(node->rightChild));
  }
  else{
    return 0;
  }

  return node->ht;
}


void insertAVL(int data){
    
    struct avl *ptr = Root, *newNode;

    if(!Root){
        Root = creatNode(data);
    }
    else{
        while(1){
            if(data <= ptr->data){
                if(ptr->leftChild){
                    ptr = ptr->leftChild;
                }
                else{
                    newNode = creatNode(data);
                    ptr->leftChild = newNode;
                    ptr = ptr->leftChild;
                    break;
                }
            }
            else{
                if(ptr->rightChild){
                    ptr = ptr->rightChild;
                }
                else{
                    newNode = creatNode(data);
                    ptr->rightChild = newNode;
                    ptr = ptr->rightChild;
                }
            }
        }
    }

    Root->ht = setHeight(Root);
}

struct avl * checkHeight(struct avl *node){
    if(node){
        if(-2 <= node->leftChild - node->rightChild   &&   node->leftChild - node->rightChild >= 2){
            return checkHeight(node->leftChild)  || checkHeight(node->rightChild);
        }
    }
    else{
        return NULL;
    }
}


int main()
{
    int input;

    while(1){
        printf("insert node: ");
        scanf("%d", &input);

        insertAVL(input);

        struct avl *check = checkHeight(Root);
        if(check){
            printf("%d  ", check->data);
        }
        else{
            continue;
        }

    }
}