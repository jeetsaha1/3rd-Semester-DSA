// Write a C program to perform addition of two polynomials using linked list.

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

    //For final expression or answer
    node *final = NULL;
    node *tail = NULL;
    node *p = exp1;
    node *q = exp2;

    while (p!= NULL && q!= NULL){
        node *nw = (node*)malloc(sizeof(node));
        nw->next = NULL;

        if(p->power == q->power){
            int sum = p->coefficient +q->coefficient;
            nw->coefficient = sum;
            nw->power = p->power;
            p = p->next;
            q = q->next;
        }
        else if(p->power > q->power){
            nw->coefficient = p->coefficient;
            nw->power = p->power;
            p = p->next;
        }
        else{
            nw->coefficient = q->coefficient;
            nw->power = q->power;
            q = q->next;
        }

        if (final == NULL)
            {final = nw;
            tail = nw;
        }
        else{
            tail ->next = nw;
            tail = nw;
        }

    }
    while (p!= NULL){
        createNode_at_last(final,p->power,p->coefficient);
        p = p->next;
    }
    while (q!= NULL){
        createNode_at_last(final,q->power,q->coefficient);
        q = q->next;
    }
    display(final);
    free_list(exp1);
    free_list(exp2);
    free_list(final);
    return 0;
}


// Enter the power of x : 2
// Enter the coefficient of x : 3
// Do you want to insert?(1/0): 1
// Enter the power of x : 1
// Enter the coefficient of x : 4
// Do you want to insert?(1/0): 1
// Enter the power of x : 0
// Enter the coefficient of x : 4
// Do you want to insert?(1/0): 0
// 3 x^(2) +4 x^(1) +4 x^(0) +0
// Enter the power of x : 1
// Enter the coefficient of x : 3
// Do you want to insert?(1/0): 1
// Enter the power of x : 5
// Enter the coefficient of x : 6
// Do you want to insert?(1/0): 0
// 3 x^(1) +6 x^(5) +0
// 3 x^(2) +7 x^(1) +6 x^(5) +4 x^(0) +0