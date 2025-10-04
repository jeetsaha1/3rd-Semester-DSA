// Write a C program to implement the concept of queue using single linked list.

#include<stdio.h>
#include<stdlib.h>

typedef struct Node{
    int data;
    struct Node *next;
}node;

node *front = NULL;
node *rear = NULL;

void *enqueue(int val){
    node *n = (node*)malloc(sizeof(node));
    if (n == NULL)
        printf("Queue Overflow");
    else{
        n->data = val;
        n->next = NULL;
        if(front == NULL)
            front = rear = n;
        else{
            rear->next = n;
            rear = n;
        }
    }
}

int dequeue(){
    int val =-1;
    if (front == NULL)
        printf("Queue Underflow");
    else{
        node *ptr = front;
        val = ptr->data;
        front = front->next;
        free(ptr);
    }
    return val;
}

void display(){
    if(front == NULL)
        printf("Empty Queue");
    else{
        node *ptr = front;
        while (ptr != rear->next)
        {
            printf("%d-->",ptr->data);
            ptr = ptr->next;
        }
        
    }
}

int main(){
    int ch = -1,val;
    do{
        printf("\n____MENU____\nEnter your choice\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            printf("Enter the value : ");
            scanf("%d",&val);
            enqueue(val);
            break;
        case 2:
            printf("The dequeued item is : %d",dequeue());
            break;
        case 3:
            display();
            break;
        default:
            break;
        }
    }while(ch != 4);
    free(front);
    free(rear);
    return 0;
}