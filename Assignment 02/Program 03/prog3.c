//Write a C program to reverse a string using appropriate ADT.

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    char *arr;
};

int isFull(struct stack * ptr){
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}   

int isEmpty(struct stack * ptr){
    if(ptr->top == -1)
        return 1;
    return 0;
}

//Declearing the push() function
void push(struct stack * ptr, char val){
    if(isFull(ptr)){
        printf("Stack overflow ");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

//Declearing the pop() function
char pop(struct stack * ptr){
    char item;
    if(isEmpty(ptr)){
        printf("Stack Unerflow");
    }
    else{
        item = ptr->arr[ptr->top];
        ptr->top--;
    }
    return item;
}

int main(){
    char *str;
    int buffer_size =100;
    str =  (char*)malloc(buffer_size*sizeof(char));
    printf("Enter the character : ");
    scanf("%s",str);
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    int len = strlen(str);
    s->size = len;
    s->arr = (char*)malloc(s->size*sizeof(char));
    for (int i = 0; str[i] != '\0'; i++)
    {
        push(s,str[i]);
    }
    for (int i = 0; str[i] != '\0'; i++)
    {
        printf("%c ",pop(s));
    }

    free(str);
    free(s->arr);
    free(s);
}