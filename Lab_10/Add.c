#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>


struct Treenode { 
 int data,ht; 
 struct Treenode *leftChild,*rightChild; 
 struct Treenode *mother; 
};

struct Treenode *Root; 

struct Treenode* createNode(int data)
{
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    return new_node;
}

void Tree_insert( int data )
{
  struct Treenode *ptr = Root, *tmp=NULL;



  while(1){
    
    if(!Root){
      Root = createNode(data);
      Root->ht = 0;
      break;
    }
    
    if(data <= ptr->data){
      if(!ptr->leftChild){
        ptr->ht++;
        ptr->leftChild = createNode(data);
        ptr->leftChild->ht=0;
        tmp = ptr->leftChild;
        tmp->mother = ptr;
        break;
      }
      ptr->ht++;
      ptr = ptr->leftChild;
    }
    else{
      if(!ptr->rightChild){
        ptr->ht--;
        ptr->rightChild = createNode(data);
        ptr->rightChild->ht=0;
        tmp = ptr->rightChild;
        tmp->mother = ptr;
        break;
      }
      ptr->ht--;
      ptr = ptr->rightChild;
    }
  }

}

void inorder(struct Treenode *r){ 
//modify inorder() from Lab9 to print balance factor
    if(r){
        inorder(r->leftChild);
        printf("%d(BF=%d)", r->data,r->ht);
        inorder(r->rightChild);
    }
}

bool checkAVL(struct Treenode *r){
    if(r){
        if(-2 <= r->ht && r->ht <=2){
            return checkAVL(r->leftChild) && checkAVL(r->rightChild);
        }
        else{
            return false;
        }
    }
    else{
        return true;
    }
}

int main()  {

    int  input;

    while(1){
        scanf("%d", &input);

        if(input>=0)
            Tree_insert(input);
        else
            break;
    }

    if(checkAVL(Root))
        // inorder(Root);
        printf("an AVL Tree");
    else
        printf("Not an AVL Tree");

    return 0;
}