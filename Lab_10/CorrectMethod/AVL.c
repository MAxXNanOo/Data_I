#include <stdio.h> 
#include <stdlib.h> 
#include <math.h>


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

int setHeight(struct Treenode *node){
  if(node){
    node->ht = 1 + fmax(setHeight(node->leftChild), setHeight(node->rightChild));
  }
  else{
    return 0;
  }

  return node->ht;
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
  
  Root->ht = setHeight(Root);
}




void inorder(struct Treenode *r){ 
    if(r){
        inorder(r->leftChild);
        printf("%d(BF=%d)",r->data, Height(r->leftChild) - Height(r->rightChild));
        inorder(r->rightChild);
    }
}




int main()  { 
    int a[]={17,3,19,1,6,18,22,4,25};    
    int i,size; 
    size=sizeof(a)/sizeof(a[0]); 
    for(i=0;i<size;i++) 
        Tree_insert (a[i]); 
    inorder(Root);    
    return 0; 
} 