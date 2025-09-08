#include <stdio.h>
#include <stdbool.h>
#define MAXTREE  15

char T[MAXTREE]={'C'};   //Initialize Tree

... LeftNode()
{

}

... RightNode()
{

}

... MotherNode()
{

}

bool isLeft(char k)
{
  if (k != 'C')
    return true;
  return false;

}
bool isRight(char k)
{
  if (k != 'C')
    return true;
  return false;

}

... SetLeft( k,  data)
{
    int index;


    if()
    {
       if()

       else
         printf("Node Inused\n");
    }
    else
      printf("Tree Overflow\n");
}

... SetRight( k,  data)
{
     int index;


    if()
    {
       if()

       else
         printf("Node Inused\n");
    }
    else
      printf("Tree Overflow\n");

}
int main()
{
    int i=0;
   SetLeft(0,'P');
   SetRight(0,'E');
   SetLeft(1,'A');
   SetRight(1,'T');
   SetLeft(2,'K');
   SetRight(2,'P');
   SetLeft(3,'S');

   SetRight(5,'X');
   SetLeft(6,'Y');

   printf("%d\n",MotherNode(1));
   printf("%d\n",MotherNode(2));
   printf("%d\n",MotherNode(3));
   printf("%c is mother node of %c\n",T[MotherNode(5)],T[5]);
   printf("%c is left node of %c\n",T[LeftNode(2)],T[2]);
   printf("%c is right node of %c\n",T[RightNode(5)],T[5]);

   printf("%d\n",isLeft(5));
   printf("%d\n",isRight(4));

  for( i=0;i<MAXTREE;i++)
      if(T[i]=='\0')
        printf(" ");
      else
       printf("%c",T[i]);
  return 0;
}