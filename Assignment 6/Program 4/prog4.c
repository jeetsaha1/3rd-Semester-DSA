// 4. Write a C program to calculate factorial with the help of stack.
#include<stdio.h>
#include<stdlib.h>

typedef struct Stack{
    int top;
    int size;
    int *arr;
}stack;

int isFull(stack *ptr){
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}

int isEmpty(stack *ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

void push(stack *ptr, int data){
    if(isFull(ptr)){
        printf("Stack Overflow");
        return;
    }
    else{
        ptr->top ++;
        ptr->arr[ptr->top] = data;
    }
}

int pop(stack *ptr){
    int item;
    if(isEmpty(ptr)){
        printf("Stack Underflow");
        return 0;
    }
    else{
        item = ptr->arr[ptr->top];
        ptr->top --;
    }
    return item;
}


int factorial(stack *sp,int num){
    sp = (stack*)malloc(sizeof(stack));
    sp->top = -1;
    sp->size = num;
    sp->arr = (int*)malloc(sp->size*sizeof(int));
    while(num>= 1){
        push(sp,num);
        num -= 1;
    }
    int fact =1;
    while (!isEmpty(sp)){
        int val = pop(sp);
        fact *= val;
    }
    return fact;

}

int main(){
    stack *sp;
    int num;
    printf("Enter the number: ");
    scanf("%d",&num);
    printf("%d",factorial(sp, num));
    return 0;
}