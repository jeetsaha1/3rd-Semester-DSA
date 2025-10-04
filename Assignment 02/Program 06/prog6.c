//Write a C program to implement queue using stack.

#include<stdio.h>
#include<stdlib.h>

//Initialize two stacks. One for enqueue and another for dequeue
struct stack1{
    int size;
    int top1;
    int *arr1;
};
struct stack2{
    int size;
    int top2;
    int *arr2;
};

//Checking condition for both stacks

int isFull1(struct stack1 * ptr){       //For first stack
    if(ptr->top1 == ptr->size-1)
        return 1;
    return 0;
}

int isEmpty1(struct stack1 * ptr){      //For first stack
    if(ptr->top1 == -1)
        return 1;
    return 0;
}

int isFull2(struct stack2 * ptr){       //For second stack
    if(ptr->top2 == ptr->size-1)
        return 1;
    return 0;
}

int isEmpty2(struct stack2 * ptr){      //For second stack
    if(ptr->top2 == -1)
        return 1;
    return 0;
}


//Declearing the push() function for both stacks

void push1(struct stack1 *ptr,int val){         //For First stack 
    if(isFull1(ptr))
        printf("Queue Overflow");
    else{
        ptr->top1++;
        ptr->arr1[ptr->top1] = val;
    }
}
void push2(struct stack2 *ptr,int val){          //For second stack 
    if(isFull2(ptr))
        printf("Queue Overflow");
    else{
        ptr->top2++;
        ptr->arr2[ptr->top2] = val;
    }
}

//Declearing the pop() function for two stacks

int pop1(struct stack1 * ptr){                  //For first stack
    int item;
    if(isEmpty1(ptr))
        printf("Queue Unerflow");
    else{
        item = ptr->arr1[ptr->top1];
        ptr->top1--;
    }
    return item;
}

int pop2(struct stack2 * ptr){                  //For second stack
    int item;
    if(isEmpty2(ptr))
        printf("Queue Unerflow");
    else{
        item = ptr->arr2[ptr->top2];
        ptr->top2--;
    }
    return item;
}

//Declearing the enqueue function with the help of first stack
void enqueue(struct stack1 * ptr,int val){
    if(isFull1(ptr))
        printf("Queue overflow ");
    else
        push1(ptr,val);
}

//Declearing the dequeue function with the help of first stack and second stack
int dequeue(struct stack1 * ptr1,struct stack2 * ptr2){
    if(isEmpty2(ptr2)){
        while(!isEmpty1(ptr1))
            push2(ptr2,pop1(ptr1));
    }
    if(isEmpty2(ptr2))
        printf("Queue underflow");

    return pop2(ptr2);
}

//Declearing the display function

void display(struct stack2 *ptr2,struct stack1 *ptr1){
    for (int i = ptr2->top2; i >= 0; i--)        //Stack 2 from top to bottom
        printf("%d ",ptr2->arr2[i]);

    for (int i = 0; i <= ptr1->top1; i++)        //Stack 1 from bottom to top
        printf("%d ",ptr1->arr1[i]);
}

int main(){
    //Initialize the structure of first and second stack and its memory space dynamically
    struct stack1 * s1 = (struct stack1 *)malloc(sizeof(struct stack1));
    struct stack2 * s2 = (struct stack2 *)malloc(sizeof(struct stack2));
    s1->top1 = s2->top2 = -1;
    s1->size = s2->size =  8;
    s1->arr1 = (int*)malloc(s1->size * sizeof(int));
    s2->arr2 = (int*)malloc(s2->size * sizeof(int));

    //For testing
    enqueue(s1,23);
    enqueue(s1,45);
    enqueue(s1,34);
    enqueue(s1,67);
    printf("Dequeued elements are: ");
    printf("%d ",dequeue(s1,s2));
    printf("%d ",dequeue(s1,s2));
    printf("%d ",dequeue(s1,s2));
    printf("\n"); 
    printf("Displayed element: ");
    display(s2,s1);

    //Free the memory space
    free(s1);
    free(s2);
    return 0;
}