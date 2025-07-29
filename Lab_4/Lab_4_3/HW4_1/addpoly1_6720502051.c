#include <stdio.h>
#include<stdlib.h>
struct polynode
{
	int coef;
	int exp;
	struct polynode *next;
};
struct polynode *head1 = NULL, *head2 = NULL, *head3 = NULL;


void displayPoly(struct polynode *head)
{
    struct polynode *ptr;
    ptr = head;
    while(ptr != NULL){
        printf("%d", ptr->coef);
        if(ptr->exp != 0)
            printf("x^%d",ptr->exp);
        ptr = ptr->next;
        if(ptr != NULL)
            printf(" + ");
    }
    printf("\n");
}
// Compare degree of exponential, return values are 0,1,-1
int compareExp(int e1,int e2)
{
    if(e1 > e2)
        return 1;
    else if(e1 == e2)
        return 0;
    else
        return -1;
}

struct polynode* createNode(int e, int c)
{
    struct polynode *new_node;
    new_node= (struct polynode*) malloc(sizeof(struct polynode));
    new_node->exp =e;
    new_node->coef = c;
    new_node->next=NULL;
    return new_node;
}

int main()
{
    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;

    int n=5,i;
    int a1[] ={6,2,3,8,0};
    int a2[] ={3,18,0,0,23};
    int ex,co;

    //create list in decreasing order add at the head
    //similar to practice
    for(i=0;i<n;i++)
    {
        p1 = createNode(i, a1[i]);
        if(p1->coef != 0){
            p1->next = head1;
            head1 = p1;
        }
        else{
            continue;
        }
    }
    printf("1st Polynomial: ");
    displayPoly(head1);

    for(i=0;i<n;i++)
    {
        p2 = createNode(i, a2[i]);
        if(p2->coef != 0){
            p2->next = head2;
            head2 = p2;
        }
        else{
            continue;
        }
    }
    printf("2nd Polynomial: ");
    displayPoly(head2);

    //add poly
    p1=head1;
    p2=head2;
    p3=head3;

    while(p1!=NULL && p2!=NULL)
    {
        switch (compareExp(p1->exp,p2->exp))
        {
            case 1:
                co = p1->coef;
                ex = p1->exp;
                p1 = p1->next;
            break;
            
            case 0:
                co = p1->coef + p2->coef;
                ex = p1->exp;
                p1 = p1->next;
                p2 = p2->next;
            break;

            case -1:
                co = p2->coef;
                ex = p2->exp;
                p2 = p2->next;
            break;
            
            
        }//end switch

        //create new node and add it in the resulted polynomial
        if(head3 == NULL){
            p3 = createNode(ex , co);
            head3 = p3;
        }
        else{
            p3->next = createNode(ex , co);
            p3 = p3->next;
        }
    }//end while

    //check whether p1 is not null, Loop for creating new node and add it in the resulted polynomial
    while(p1 != NULL){
        p3 = createNode(p1->exp , p1->coef);
        p3->next = head3;
        head3 = p3;
    }

   //check whether p2 is not null, Loop for creating new node and add it in the resulted polynomial
    while(p2 != NULL){
        p3 = createNode(p2->exp , p2->coef);        
        p3->next = head3;
        head3 = p3;
    }

    // Display resultant List
    printf("\nAdded polynomial: ");
    displayPoly(head3);

    //free memory
    return 0;
}//end main