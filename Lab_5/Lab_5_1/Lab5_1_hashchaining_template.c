#include<stdio.h>
#include<stdlib.h>
#define Size 7

struct  node
{
  int data;
  struct node *next;
};
struct node *hash_table[Size];   //array of pointer

void insertChain(int value)
{
  struct node *new_node;
  new_node= (struct node*) malloc(sizeof(struct node));
  //assign value to the new_node
  new_node->data = value;
  new_node->next=NULL;

  int h = value % Size;
  struct node *ptr=hash_table[h];
  if(!ptr){
    hash_table[h] = new_node;
  }
  else{
    new_node->next = hash_table[h];
    hash_table[h] = new_node;
    // printf("INPUT %d   ",value);
  }

}

void printChain()
{
  int i;
  struct node *ptr;
  for(i=0 ; i<Size ; i++){
    // if(hash_table[i]){
    //   ptr = hash_table[i];
    //   do{
    //     printf("%d->",ptr->data);
    //     ptr = ptr->next;
    //   }while(ptr);
    //   printf("\n| End loop\n");
    // }
    printf("chain[%d]-->",i);

    if(hash_table[i]){
      ptr = hash_table[i];
      do{
        printf("%d ",ptr->data);
        ptr = ptr->next;
        if(ptr)
          printf("-->");
        else
          printf("-->NULL\n");
      }while(ptr);
    }
    else{
      printf("NULL\n");
    }
  }
}


int main()
{
   int i;

   for(i=0;i<Size;i++)     //initialize a chained hash table
     hash_table[i]=NULL;

  insertChain(15);
  insertChain(22);
  insertChain(95);
  insertChain(56);
  insertChain(12);
  insertChain(27);
  insertChain(63);

//  insertChain(49);
//  insertChain(24);
 printChain();



 return 0;
}
