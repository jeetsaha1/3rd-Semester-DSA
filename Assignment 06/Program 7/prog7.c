// 7. Write a C program to validate the parenthesis of an expression.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Stack{
    int size;
    int top;
    char *arr; 
}stack;

int isFull(stack *sp){
    if (sp->top == sp->size-1)
        return 1;
    return 0;
}

int isEmpty(stack *sp){
    if (sp->top == -1)
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

char pop(stack *sp){
    char item;
    if(isEmpty(sp))
        printf("Stack Underflow");
    else{
        item = sp->arr[sp->top];
        sp->top -- ;
    }
    return item;
}

int match(char a, char b){
    if (a == '(' && b == ')')
        return 1;
    if (a == '[' && b == ']')
        return 1;
    if (a == '{' && b == '}')
        return 1;
    return 0;
}

int validate_parenthesis(char *exp){
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->top = -1;
    sp->size = strlen(exp);
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char poped_ele;
    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '('||exp[i] == '['||exp[i] == '{')
            push(sp,exp[i]);
        else if(exp[i] == ')'||exp[i] == ']'||exp[i] == '}'){
            if(isEmpty(sp))
                return 0;
            poped_ele = pop(sp);
            if(!match(poped_ele,exp[i]))
                return 0;   
        }
    }
    if(isEmpty(sp))
        return 1;
    else
        return 0;
    
}

int main(){
     char *exp = "(1)}";
    if(validate_parenthesis(exp))
        printf("The parenthesis is matched.");
    else
        printf("The parenthesis is not matched.");
    return 0;
}