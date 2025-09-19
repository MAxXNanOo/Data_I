#include <stdio.h>
#include <stdlib.h>

struct Treenode {
 int data;
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

void Inorder( struct Treenode * ptr)
{
    if(ptr){
        Inorder(ptr->leftChild);
        printf("%d ",ptr->data);
        Inorder(ptr->rightChild);
    }
}

struct Treenode * Tree_Find(struct Treenode * ptr , int data)
{
    while(ptr->data!=data){
        if(data < ptr->data)
            ptr = ptr->leftChild;
        else if(data > ptr->data)
            ptr = ptr->rightChild;
    }
    return ptr;
}

struct Treenode * FindMin( struct Treenode * ptr)
{
  while(ptr->leftChild){
    ptr = ptr->leftChild;
  }
  return ptr;
}

struct Treenode * FindMax( struct Treenode * ptr)
{
  while(ptr->rightChild){
    ptr = ptr->rightChild;
  }
  return ptr;
}

void Tree_delete(struct Treenode *ptr , int data)
{
    struct Treenode *x = Tree_Find(ptr, data);

    // printf("taget = %d",taget->data);
    if(!x){
        printf("value is not found in the tree\n");
    }
    else{
        struct Treenode *tmpLeft=x->leftChild, *tmpRight = x->rightChild, *tmpMother = x->mother, *supertmp=NULL;

        if(tmpLeft){
            tmpLeft->mother = tmpMother;
            tmpRight->mother = tmpLeft;
            tmpLeft->rightChild = tmpRight;
            supertmp = tmpLeft;

            // if(tmpLeft->rightChild){
            //     struct Treenode *new = Tree_insert(24);
            //     new->mother = tmpLeft->rightChild->mother;
            //     if(new->mother->leftChild = new){
            //         new->mother->leftChild = tmpLeft->rightChild;
            //     }else{
            //         new->mother->rightChild = tmpLeft->rightChild;
            //     }
            // }
        }

        
        if(x->data < tmpMother->data){
            tmpMother->leftChild = supertmp;
        }
        else{
            tmpMother->rightChild = supertmp;
        }

        x->mother = NULL;
        x->leftChild = NULL;
        x->rightChild = NULL;
    }
}



int main()
{
  int a[]={56,26,200,18,28,190,213,12,24,27};
  int i,size;
  size=sizeof(a)/sizeof(a[0]);

  for(i=0;i<size;i++)
        Tree_insert(a[i]);

   printf("Min=%d\n",FindMin(Root)->data);
   printf("Max=%d\n",FindMax(Root)->data);

   struct Treenode *p;
   p=Tree_Find(Root,190);
   
     if(p!=NULL)
       printf("Found\n");
     else
       printf("Not found\n");
   
    Inorder(Root);
    printf("\n");
   Tree_delete(Root,190);
   Tree_delete(Root,26);

   Inorder(Root);
}