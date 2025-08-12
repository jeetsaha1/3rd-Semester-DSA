// Write a C program to perform multiplication of two polynomials using linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int coefficient;
    int power;
    struct Node *next;
}node;

node *createNode(){
    node *nw, *head = NULL;
    int coeff,pow, ch = -1;
    while (ch!= 0 ){
        printf("Enter the power of x : ");
        scanf("%d",&pow);
        printf("Enter the coefficient of x : ");
        scanf("%d",&coeff);

        nw =  (node*)malloc(sizeof(node));
        nw->coefficient = coeff;
        nw->power = pow;
        nw->next = NULL;

        if (head == NULL)
            head = nw;
        else{
            node *p = head;
            while (p->next!=NULL)
                p = p->next;
            p->next = nw;
            nw->next = NULL;
        }

        printf("Do you want to insert?(1/0): ");
        scanf("%d",&ch);
    }
    return head;
}

node *createNode_at_last(node *head, int power, int coefficient){
    node *nw, *p;
    nw = (node*)malloc(sizeof(node));
    nw->power = power;
    nw->coefficient = coefficient;
    nw->next = NULL;
    if (head == NULL)
        head = nw;
    else{
        p = head;
        while (p->next!= NULL)
            p = p->next;
        p->next = nw;
        nw->next = NULL;
    }
    return head;
}
void display(node *head){
    node *temp = head;
    while (temp!= NULL){
        printf("%d x^(%d) +",temp->coefficient,temp->power);
        temp = temp->next;
    }
    printf("0");
}

void free_list(node* head) {
    node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main(){
    //For first expression
    node *exp1;
    exp1 = createNode();
    display(exp1);
    printf("\n");

    //For second expression
    node *exp2;
    exp2 = createNode();
    display(exp2);
    printf("\n");

    //For multiplying two expressions
    node* result = NULL;
    node* tail = NULL;
    while (exp1!= NULL){
        while(exp2 != NULL){
            int mul = exp1->coefficient * exp2->coefficient;
            int pow = exp1->power + exp2->power;
            node *nw = (node*)malloc(sizeof(node));
            nw->coefficient = mul;
            nw->power = pow;
            nw->next = NULL;
           
            if (result == NULL){
                result = nw; 
                tail = nw;
            }
            else{
                tail->next = nw;
                tail = nw;
            }
            exp1 = exp1->next;
        }
        exp2 = exp2->next;
    }
    display(result);
    free_list(result);
    free_list(exp1);
    free_list(exp2);
    return 0;
}

