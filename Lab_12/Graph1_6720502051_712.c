#include <stdio.h>
#define max 100
int n,head=-1,tail=-1,top=-1;      //number of vertices
int S[max],Q[max];
//stack functions & variables
void push(int data){
   if(top==max-1)
      printf("stack ovrflow");
   else{
      top++;
      S[top]=data;
   }
}

int pop(){
   if(top==-1)
      printf("underflow");
   else{
      int data = S[top];
      top--;
      return data;
   }
}
//queue functions & variables
void enqueue(int data){
      if(tail==max-1)
         printf("overflow");
      else{
         if(tail==-1&&head==-1){
            tail=0;
            head=0;
         }
         else
            tail++;
         
      }
}

void DFT(char *V,int G[][n],int status[]) //suggest list of parameter of function
{

}

void BFT(char *V,int G[][n],int status[]) //suggest list of parameter of function
{

}

int main()
{
   int i,j;
   printf("Enter number of vertices:");
   scanf("%d",&n);

   int status[n];           // Array for tracking status of each node
   int G[n][n];             // Array for representing Graph
   char V[n+1];             // Array for representing set of vertices

   printf("Enter node's name:");
   //Fill in your code
   scanf("%s", &V);

   printf("Enter the adjacency matrix:\n");
   //Fill in your code
   for(i=0 ; i<n ; i++){
      for(j=0 ; j<n ; j++){
         scanf("%d", G[i][j]);
      }
   }

   printf("DFS Traversal: ");
   DFT(V,G,status);

   printf("\nBFS Traversal: ");
   BFT(V,G,status);
}