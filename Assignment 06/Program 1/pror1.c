// Write a C program to evaluate a postfix expression.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
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

void push(stack *sp, int val){
    if(isFull(sp))
        printf("Stack Overflow");
    else{
        sp->top++;
        sp->arr[sp->top] = val;
    }
}

int pop(stack *sp){
    int item;
    if(isEmpty(sp))
        printf("Stack Underflow");
    else{
        item = sp->arr[sp->top];
        sp->top -- ;
    }
    return item;
}

int peep(stack *sp){
    return sp->arr[sp->top];
}

int isOperator(char a){
    if (a == '+'||a == '-'||a == '*'||a == '/')
        return 1;
    else
        return 0;
}

int postfix_evaluate(char *exp){
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->top = -1;
    sp->size = strlen(exp);
    sp->arr = (int*)malloc((sp->size+1)*sizeof(int));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if(!isOperator(exp[i])){
            push(sp,exp[i]-'0');
        }
        else{
            if (exp[i] == '+'){
                int x = pop(sp);
                int y = pop(sp);
                int res = y+x;
                push(sp,res);
            }
            else if (exp[i] == '-'){
                int x = pop(sp);
                int y = pop(sp);
                int res = y- x;
                push(sp,res);
            }
            else if (exp[i] == '*'){
                int x = pop(sp);
                int y = pop(sp);
                int res = y* x;
                push(sp,res);
            }
            else if (exp[i] == '/'){
                int x = pop(sp);
                int y = pop(sp);
                int res = y/ x;
                push(sp,res);
            }
        }
    }
    int val = pop(sp);
    return val;
    
}

int main(){
    char *val ="234*6/+";
    printf("%d",postfix_evaluate(val)); 
    return 0;
}