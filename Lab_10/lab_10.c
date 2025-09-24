#include <stdio.h> 
#include <stdlib.h>
#include <math.h>


struct Treenode { 
 int data,ht; 
 struct Treenode *leftChild,*rightChild; 
 struct Treenode *mother; 
};


struct Treenode *Root,*S[100];

int height(struct Treenode *ptr)
{
    if(ptr!=NULL)
        return 1;
    return 0;
} 

struct Treenode* createNode(int data)
{
    struct Treenode *new_node;
    new_node= (struct Treenode*) malloc(sizeof(struct Treenode));
    new_node->data =data;
    new_node->leftChild =NULL;
    new_node->rightChild=NULL;
    new_node->mother=NULL;
    new_node->ht=1;
    return new_node;
}

void Tree_insert( int data )
{
  struct Treenode *ptr = Root, *tmp=NULL,*x=createNode(data);
  int top=-1;
   top++;
   //printf("%d",top);
   S[top]=ptr;
    if(Root==NULL){
      Root = x;
    }
    else{
    if(data <= ptr->data){
      if(!ptr->leftChild){
        ptr->leftChild = x;
        tmp = ptr->leftChild;
        tmp->mother = ptr;
      }
      ptr = ptr->leftChild;
    }
    else{
      if(!ptr->rightChild){
        ptr->rightChild = x;
        tmp = ptr->rightChild;
        tmp->mother = ptr;
        //break;
      }
      ptr = ptr->rightChild;
    }
  }
  while(top!=-1){
    printf("%d",top);
    struct Treenode *t=S[top];
    t->ht=height(t)+1;
    top--;
  }

}



void inorder(struct Treenode *r){ 
//modify inorder() from Lab9 to print balance factor
    if(r){
        inorder(r->leftChild);
        printf("%d(BF=%d)", r->data, r->ht);
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