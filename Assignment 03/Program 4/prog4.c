// Write a C program to store polynomial using linked list. Store the term in ascending
// order.

#include<stdio.h>
#include<stdlib.h>

//Make a structure for making a node for every operands of the polynomial
typedef struct Node{
    int coeff;
    int power;
    struct Node * next;
}node;

//Arrangement the node 
node *createNode(){
    node *head = NULL, *nw;
    int pow, coef, ch=1;
    while(ch != 0){
        printf("Enter the coefficient of the polynominal: ");
        scanf("%d",&coef);
        printf("Enter the power of the coefficient: ");
        scanf("%d",&pow);

        nw = (node*)malloc(sizeof(node));
        nw->coeff = coef;
        nw->power = pow;
        nw->next = NULL;

        if(head == NULL || head->power > pow){
            nw->next = head;
            head = nw;
        } 
        else{
            node *p = head;
            while (p->next!= NULL && p->next->power <pow)
            {
                p = p->next;
            }
            nw->next = p->next;
            p->next = nw;
            
        }

        printf("Do you want to insert: ");
        scanf("%d",&ch);
    }
    
    return head;
}

void display(node *head){
    node *p = head;
    while (p != NULL){
        printf("%d x^(%d)+",p->coeff,p->power);
        p = p->next;
    }
    printf("0");
}

int main(){
    node *h ;
    h = createNode();
    display(h);
    return 0;
}