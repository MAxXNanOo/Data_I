#include <stdio.h>
#include <stdlib.h>


struct Treenode {
    char data;
    struct Treenode *leftChild;
    struct Treenode *rightChild;
    struct Treenode *mother;
};

struct Treenode *Root = NULL;

struct Treenode * createNode(char data)
{
    struct Treenode *new = (struct Treenode *)malloc(sizeof(struct Treenode));
    new->data = data;
    new->leftChild = NULL;
    new->rightChild = NULL;
    return new;
}

void Tree_insert( char data )
{
  struct Treenode *ptr = Root, *tmp=NULL;

  while(1){
    if(!Root){
      Root = createNode(data);
      break;
    }
        
    if(data < ptr->data){
      if(!ptr->leftChild){
        ptr->leftChild = createNode(data);
        tmp = ptr->leftChild;
        tmp->mother = ptr;
        break;
      }
      ptr = ptr->leftChild;
    }
    else if(data > ptr->data){
      if(!ptr->rightChild){
        ptr->rightChild = createNode(data);
        tmp = ptr->rightChild;
        tmp->mother = ptr;
        break;
      }
      ptr = ptr->rightChild;
    }
    else{
        break;
    }
  }

}


struct Treenode * Tree_Find(struct Treenode * ptr , char data)
{
    while(ptr){
        if(ptr->data!=data){
            if(data < ptr->data)
                ptr = ptr->leftChild;
            else if(data > ptr->data)
                ptr = ptr->rightChild;            
        }
        else{
            break;
        }

    }
    return ptr;
}

int Tree_Find_Index(struct Treenode * ptr , char data)
{
    int count=0;
    while(ptr){
        if(data < ptr->data)
            ptr = ptr->leftChild;
        else if(data > ptr->data)
            ptr = ptr->rightChild;
        else if(data == ptr->data)
            return count;

        count++;
    }
    return -1;
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


// void Tree_delete(struct Treenode *ptr , char data)
// {
//   struct Treenode *x,*y;
//   x = Tree_Find(ptr, data);
// //   printf("run");
//   if(!x){
//     printf("-1");
//   }
//   else{
    
//     if(x->leftChild){
//       y = FindMax(x->leftChild);
//       x->data = y->data;

//       if(y->mother->leftChild == y)
//         y->mother->leftChild = y->rightChild;
//       else
//         y->mother->rightChild = y->rightChild;

//       if(y->leftChild)
//         y->leftChild->mother = y->mother;
//       free(y);
//     }
//     else if(x->rightChild){
//       y = FindMin(x->rightChild);
//       x->data = y->data;
      
//       if(y->mother->leftChild == y)
//         y->mother->leftChild = y->leftChild;
//       else
//         y->mother->rightChild = y->leftChild;

//       if(y->rightChild)
//         y->rightChild->mother = y->mother;
        
//       free(y);
//     }
//     // else{
//     //   if(x->mother->leftChild == x){
//     //     x->mother->leftChild = NULL;
//     //   }
//     //   else{
//     //     x->mother->rightChild = NULL;
//     //   }
//     //   free(x);
//     // }

//         if (x->mother) {
//             if (x->mother->leftChild == x)
//                 x->mother->leftChild = NULL;
//             else
//                 x->mother->rightChild = NULL;
//         } else {
//             // ลบ root ที่ไม่มีลูก
//             Root = NULL;
//         }
//         free(x);

//   }
// }



void Tree_delete(struct Treenode *ptr , char data)
{
    struct Treenode *x, *y;
    x = Tree_Find(ptr, data);
    if (!x) {
        printf("-1");
        return;
    }

    // กรณีมีลูกซ้าย
    if (x->leftChild) {
        y = FindMax(x->leftChild);
        x->data = y->data;

        // เชื่อมลูกของ y กลับไปหาแม่ของ y
        if (y->mother->rightChild == y)
            y->mother->rightChild = y->leftChild;
        else
            y->mother->leftChild = y->leftChild;

        if (y->leftChild)
            y->leftChild->mother = y->mother;

        free(y);
    }

    // กรณีไม่มีลูกซ้าย แต่มีลูกขวา
    else if (x->rightChild) {
        y = FindMin(x->rightChild);
        x->data = y->data;

        if (y->mother->leftChild == y)
            y->mother->leftChild = y->rightChild;
        else
            y->mother->rightChild = y->rightChild;

        if (y->rightChild)
            y->rightChild->mother = y->mother;

        free(y);
    }

    // กรณีไม่มีลูกทั้งซ้ายและขวา
    else {
        if (x->mother) {
            if (x->mother->leftChild == x)
                x->mother->leftChild = NULL;
            else
                x->mother->rightChild = NULL;
        } else {
            // ลบ root ที่ไม่มีลูก
            Root = NULL;
        }
        free(x);
    }
}





void preorder(struct Treenode *ptr)
{
    if(ptr){
        printf("%c", ptr->data);
        preorder(ptr->leftChild);
        preorder(ptr->rightChild);
    }
}

void inorder(struct Treenode *ptr)
{
    if(ptr){
        inorder(ptr->leftChild);
        printf("%c",ptr->data);
        inorder(ptr->rightChild);
    }
}

void postorder(struct Treenode *ptr)
{
    if(ptr){
        postorder(ptr->leftChild);
        postorder(ptr->rightChild);
        printf("%c",ptr->data);
    }
}




int main()
{
    char input[50];

    scanf("%s", input);
    for(int i=0 ; input[i] != '\0' ; i++){
        if('A' <= input[i] && input[i] <= 'Z'){
            if(!Tree_Find(Root, input[i])){
                Tree_insert(input[i]);
            }
        }
        else{
            switch(input[i]){
                case '0':
                    i++;
                    // printf("delete %c   ",input[i]);
                    Tree_delete(Root, input[i]);
                break;

                case '1':
                    i++;
                    printf("%d", Tree_Find_Index(Root, input[i]));
                break; 

                case '2':
                    preorder(Root);
                break;

                case '3':
                    inorder(Root);
                break;

                case '4':
                    postorder(Root);
                break;

                case '5':
                    printf("%c%c", FindMin(Root)->data, FindMax(Root)->data);
                break;
                
            }
        }
    }

    
}