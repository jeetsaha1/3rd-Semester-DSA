// Write a C program to implement the concept of double stack, where both end can be used for operations.

//Initialize two stacks
#include<stdio.h>
#include<stdlib.h>

struct stack1{
    int top1;
    int top2;
    int *arr1;
    int size;
};

int isFull(struct stack1 * ptr1){
    if(ptr1->top1+1 == ptr1->top2){
        return 1;
    }
    return 0;
}

int isEmpty1(struct stack1 * ptr1){
    if(ptr1->top1 ==-1 ){
        return 1;
    }
    return 0;
}

int isEmpty2(struct stack1 * ptr1){
    if( ptr1->top2 == ptr1->size){
        return 1;
    }
    return 0;
}

void push1(struct stack1 * ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top1++;
        ptr->arr1[ptr->top1] = val;
    }
}

void push2(struct stack1 * ptr,int val){
    if(isFull(ptr)){
        printf("Stack Overflow");
    }
    else{
        ptr->top2--;
        ptr->arr1[ptr->top2] = val;
    }
}

int pop1(struct stack1 * ptr){
    int item;
    if(isEmpty1(ptr)){
        printf("Stack Underflow");
    }
    else{
        item = ptr->arr1[ptr->top1];
        ptr->top1--;
    }
    return item;
}

int pop2(struct stack1 * ptr){
    int item;
    if(isEmpty2(ptr)){
        printf("Stack Underflow");
    }
    else{
        item = ptr->arr1[ptr->top2];
        ptr->top2++;
    }
    return item;
}

int main(){
    struct stack1 * s= (struct stack1*)malloc(sizeof(struct stack1));
    s->size = 8;
    s->top1 = -1;
    s->top2 = s->size;
    s->arr1 = (int*)malloc(s->size*sizeof(int));
    push1(s,10);
    push2(s,100);
    push1(s,20);
    push2(s,200);

    printf("Pop from Stack1: %d\n", pop1(s));
    printf("Pop from Stack2: %d\n", pop2(s));
    printf("Pop from Stack1: %d\n", pop1(s));
    printf("Pop from Stack2: %d\n", pop2(s));

    free(s->arr1);
    free(s);
    return 0;
}