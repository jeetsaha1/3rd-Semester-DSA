// Write a C program to implement stack using dynamic array and perform the following operation • PUSH() • POP() • PEEK() • DISPLAY(). Mention the necessary algorithm.

#include<stdio.h>
#include<stdlib.h>

struct stack{
    int size;
    int top;
    int *arr;
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
void push(struct stack * ptr){
    if(isFull(ptr)){
        printf("Stack overflow ");
    }
    else{
        int val;
        printf("Enter the value: ");
        scanf("%d",&val);
        ptr->top++;
        ptr->arr[ptr->top] = val;
    }
}

//Algorithm for push()
/*
PUSH(stack, value)
BEGIN
    IF top == size THEN
        PRINT "Stack Overflow"
    
    ELSE
        top := top + 1
        stack[top] := value
    ENDIF
END
*/


//Declearing the pop() function
int pop(struct stack * ptr){
    int item;
    if(isEmpty(ptr)){
        printf("Stack Unerflow");
    }
    else{
        item = ptr->arr[ptr->top];
        ptr->top--;
    }
    return item;
}

//Algorithm for pop()
/*
POP(stack)
BEGIN
    IF top == -1 THEN 
        PRINT "Stack Underflow"
        RETURN null
    ELSE
        value := stack[top]
        top := top-1
        RETURN value
    ENDIF
END
*/

//Declearing the peek function
int peek(struct stack * ptr){
    if(isEmpty(ptr)){
        printf("Empty stack");
    }
    return ptr->arr[ptr->top];
}

//Algorithm for Peek()
/*
PEEK(stack)
BEGIN
    IF top == -1 THEN 
        PRINT "Empty Stack"
        RETURN null
    ELSE
        RETURN stack[top]
    ENDIF
END
*/

//Declearing the display function
void display(struct stack *ptr){
    for (int i = 0; i <= ptr->top; i++)
    {
        printf("%d ",ptr->arr[i]);
    }
    
}

//Algorithm for display()
/*
DISPLAY(stack)
BEGIN
    IF top == -1 THEN 
        PRINT "Empty Stack"
    ELSE
        FOR i ← top DOWNTO 0 DO
            PRINT stack[i]
        ENDFOR
    ENDIF
END
*/

int main(){
    //Initialize the structure and its memory space dynamically
    struct stack * s = (struct stack *)malloc(sizeof(struct stack));
    s->top = -1;
    s->size = 8;
    s->arr = (int*)malloc(s->size * sizeof(int));

    //Make a chioce
    int ch;
    do{
        printf("\n____Menu____\nEnter your choice: \n1.Push \n2.Pop \n3.Peek \n4.Display\n_____________________\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            push(s);
            break;
        case 2:
            printf("Poped item : %d\n",pop(s));
            break;
        case 3:
            printf("The top most element of the stack : %d\n",peek(s));
            break;
        case 4:
            display(s);
            break;
        case 5:
            printf("Exiting...");
            break;
        default:
            printf("You give wrong input");
            break;
        }
    }while(ch!= 5);
    free(s->arr);
    return 0;
}