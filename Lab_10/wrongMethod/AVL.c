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
      break;
    }
        
    if(data <= ptr->data){
      if(!ptr->leftChild){
        ptr->leftChild = createNode(data);
        tmp = ptr->leftChild;
        tmp->mother = ptr;
        break;
      }
      ptr = ptr->leftChild;
    }
    else{
      if(!ptr->rightChild){
        ptr->rightChild = createNode(data);
        tmp = ptr->rightChild;
        tmp->mother = ptr;
        break;
      }
      ptr = ptr->rightChild;
    }
  }

}

int height(struct Treenode *ptr)
{
    if(ptr){
        return 1 + fmax(height(ptr->leftChild), height(ptr->rightChild));
    }else{
        return 0;
    }
}

void inorder(struct Treenode *r){ 
//modify inorder() from Lab9 to print balance factor
    if(r){
        inorder(r->leftChild);
        printf("%d(BF=%d)", r->data, height(r->leftChild)-height(r->rightChild));
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