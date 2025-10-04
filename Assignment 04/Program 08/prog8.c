// Write a C program to implement the concept of stack using single linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data ;
    struct Node *next;
}node;

node *top = NULL;

int isFull(){
    node *n = (node*)malloc(sizeof(node));
    if (n == NULL){
        return 1;
    }
    free(n);
    return 0;
}

node *push(int val){
    if (isFull()){
        printf("Stack Overflow");
    }
    else{
        node *nw = (node*)malloc(sizeof(node));
        nw->data = val;
        nw->next = top;
        top = nw;
        return top;
    }
}

int pop(){
    if (top == NULL)
        printf("Stack Underflow");
    else{
        node *tp = top;
        int item = tp->data;
        top = tp->next;
        free(tp);
        return item;
    }
}

int peep(){
    if (top== NULL)
        {printf("Empty stack");
        return -1;}
    else{
        return top->data;
    }
}

void display(){
    if (top== NULL)
        {printf("Empty stack");
        return ;
    }
    node *ptr = top;
    while(ptr != NULL){
        printf("%d -->",ptr->data);
        ptr = ptr->next;
    }
    printf("NULL");
}

int main(){
    int ch = -1,val;
    do{
        printf("\n____MENU____\nEnter your choice\n1.Push\n2.Pop\n3.Peep\n4.Display\n5.Exit\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d",&val);
            top = push(val);
            break;
        case 2:
            printf("The poped item is : %d",pop(top));
            break;
        case 3:
            printf("The top value is: %d",peep(top));
            break;
        case 4:
            display();
            break;
        default:
            break;
        }
    }while(ch != 5);
    free(top);
    return 0;
}