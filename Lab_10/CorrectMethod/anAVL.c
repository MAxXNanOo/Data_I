#include <stdio.h> 
#include <stdlib.h> 


struct Treenode { 
    int data,ht; 
    struct Treenode *leftChild,*rightChild; 
    struct Treenode *mother; 
};

struct Treenode *Root;

struct Treenode* createNode(int data)
{
    struct Treenode *new_node;
    new_node = (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->leftChild = NULL;
    new_node->rightChild = NULL;
    new_node->mother = NULL;
    return new_node;
}


int Height(struct Treenode *x){
    if(!x){
        return 0;
    }
    else{
        return x->ht;
    }
}

void Tree_insert( int data )
{
  struct Treenode *ptr = Root, *tmp=NULL;

  while(1){
    if(!Root){
      Root = createNode(data);
      Root->ht = 1;
      break;
    }
        
    if(data < ptr->data){
      if(!ptr->leftChild){
        ptr->leftChild = createNode(data);
        tmp = ptr->leftChild;
        tmp->ht = 1;
        tmp->mother = ptr;
        break;
      }
      ptr = ptr->leftChild;
    }
    else if(data > ptr->data){
      if(!ptr->rightChild){
        ptr->rightChild = createNode(data);
        tmp = ptr->rightChild;
        tmp->ht = 1;
        tmp->mother = ptr;
        break;
      }
      ptr = ptr->rightChild;
    }
    else{
        break;
    }
}
  
  ptr = Root;
  while(ptr){
    if(ptr->data == data){
        break;
    }
    else{
        if(data < ptr->data){
            ptr->ht = 1 + Height(ptr->leftChild);
            ptr = ptr->leftChild;
        }
        else{
            ptr->ht = 1 + Height(ptr->rightChild);
            ptr = ptr->rightChild;
        }
    }
  }
}




void inorder(struct Treenode *r){ 
    if(r){
        inorder(r->leftChild);
        printf("%d(BF=%d)",r->data, Height(r->leftChild) - Height(r->rightChild));
        inorder(r->rightChild);
    }
}




int main()  { 
    int input;
    while(1){
        scanf("%d", &input);
        if(input>=0){
            Tree_insert(input);
        }
        else{
            break;
        }
    }
} 