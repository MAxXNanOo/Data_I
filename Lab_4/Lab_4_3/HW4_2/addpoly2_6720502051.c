#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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

void sortExp(struct polynode *head, int round){
    struct polynode *ptr = head,*pre;
    int i=0,tmp1,tmp2;
    for(i=0 ; i<round ; i++){
        ptr=head;
        do{
            pre = ptr;
            ptr = ptr->next;
            if(ptr==NULL)
                break;
            if(pre->exp < ptr->exp){
                tmp1 = pre->exp;
                pre->exp = ptr->exp;
                ptr->exp = tmp1;
            }
        }while(ptr != NULL);
    }
}
// SUPER MEGA ERROR!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// if(pre->exp < ptr->exp && ptr!=NULL)
// Can't cheak ptr!=NULL and !(ptr == NULL) when check data in struct T^T

int main()
{
    struct polynode *p1 = NULL, *p2 = NULL, *p3 = NULL;
    struct polynode *new_node;

    int n=0,i=0,arr[100];
    int ex,co;
    srand(time(NULL));

    printf("==== Create 1st Polynomial ==== \n");
    while(n>=0){
        printf("Enter exponential:");
        scanf("%d",&n);
        if(n>=0){
            p1 = createNode(n, rand()%30+1);
            p1->next = head1;
            head1 = p1;
            i++;
        }
    }
    sortExp(head1,i);
    printf("1st Polynomial: ");
    displayPoly(head1);

    n=0,i=0;
    printf("\n==== Create 2st Polynomial ==== \n");
    while(n>=0){
        printf("Enter exponential:");
        scanf("%d",&n);
        if(n>=0){
            p2 = createNode(n, rand()%30+1);
            p2->next = head2;
            head2 = p2;
            i++;
        }
    }
    sortExp(head2,i);
    printf("2nd Polynomial: ");
    displayPoly(head2);

    
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
    printf("\nAdded polynomial: ");
    displayPoly(head3);

    return 0;
}//end main