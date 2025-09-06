// 6. Write a C program to reverse a string using stack.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct stack{
    int top;
    int size;
    char *arr;
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

void reverse_string(char *str){
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->top = -1;
    sp->size = strlen(str);
    sp->arr = (char*)malloc((sp->size+1)*sizeof(char));

    for (int i = 0; str[i] != '\0'; i++)
    {
        push(sp,str[i]);
    }
    while (sp->top != -1)
    {
        printf("%c",pop(sp));
    }
}

int main(){
    char *str;
    printf("Enter the string: ");
    scanf("%s",str);
    reverse_string(str);
    return 0;
}