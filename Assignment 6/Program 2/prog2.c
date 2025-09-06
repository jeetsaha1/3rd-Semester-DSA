//infix to postfix operation
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//Implementing the structure stack
typedef struct Stack{
    char *arr;
    int size;
    int top;
}stack;

//Defining the function isFull
int isFull(stack *ptr){
    if(ptr->top == ptr->size-1)
        return 1;
    return 0;
}

//Defining the function isEmpty
int isEmpty(stack *ptr){
    if (ptr->top == -1)
        return 1;
    return 0;
}

void push(stack *ptr, int val){
    if(isFull(ptr)){
        printf("Stack Overflow");
        return ;
    }
    else{
        ptr->top ++;
        ptr->arr[ptr->top] = val;
    }
}

char pop(stack *ptr){
    if(isEmpty(ptr)){
        printf("Empty Stack");
        return 0;
    }
    else{
        char item = ptr->arr[ptr->top];
        ptr->top --;
        return item;
    }
}

void display(stack *ptr){
    if(isEmpty(ptr))
        printf("Empty Stack");
    else{
        for (int i = ptr->top; i >= 0; i--)
        {
            printf("%c",(ptr->arr)[i]);
        }
        
    }
} 

int stackTop(stack *ptr){
    return ptr->arr[ptr->top];
}

int stackBottom(stack * ptr){
    return ptr->arr[0];
}

int isOperator(char a){
    if(a == '+' ||a == '-' ||a == '*' ||a == '/' )
        return 1;
    else
        return 0;
}

int precedence(char a){
    if (a == '*' || a == '/')
        return 3;
    else if(a == '+' || a == '-')
        return 2;
    else
        return 0;
}

char *infix_to_postfix(char *infix){
    stack *sp = (stack*)malloc(sizeof(stack));
    sp->top = -1;
    sp->size = strlen(infix);
    sp->arr = (char*)malloc(sp->size*sizeof(char));
    char *postfix = (char*)malloc((strlen(infix)+1)*sizeof(char));

    int i = 0;  //Infix scanner
    int j = 0;  //Postfix filler

    while(infix[i] != '\0'){
        if (infix[i] == '('){
            push(sp,infix[i]);
            i++;
        }
        else if (!isOperator(infix[i]) && infix[i] != ')'&& infix[i] != '('){
            postfix[j] = infix[i];
            i++;
            j++;
        }
        else if (isOperator(infix[i])){
            while (!isEmpty(sp) && precedence(stackTop(sp))>precedence(infix[i])){
                int temp = pop(sp);
                postfix[j] = temp;
                j++;
            }
            push(sp,infix[i]);
            i++;
        }
        else if(infix[i] == ')'){
            while (stackTop(sp) != '('){
                postfix[j++] = pop(sp);
            }
            pop(sp);
            i++;
        }
    }
    while (!isEmpty(sp))
    {
        // if (stackTop(sp) == '(' || stackTop(sp) == ')')
        //     pop(sp);
        postfix[j] = pop(sp);
        j++;
    }
    postfix[j] = '\0';
    return postfix;
}

int main(){
    char * infix;
    printf("Enter the expression: ");
    scanf("%s",infix);
    printf("%s",infix_to_postfix(infix));
    return 0;
}