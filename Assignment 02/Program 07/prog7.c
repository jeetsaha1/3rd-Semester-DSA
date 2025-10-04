//Write a C program to implement circular queue.

#include<stdio.h>
#include<stdlib.h>

//Initializing the queue structure
struct queue{
    int size;
    int f;
    int r;
    int *arr;
};

int isFull(struct queue * q){
    if((q->r+1)%q->size == q->f)
        return 1;
    return 0;
}

int isEmpty(struct queue * q){
    if(q->r == q->f)
        return 1;
    return 0;
}

//Declearing the function enqueue()
void enqueue(struct queue * q){
    int val;
    if(isFull(q)){
        printf("Queue overflow");
    }
    else{            
        printf("Enter the number :");
        scanf("%d",&val);
        q->r= (q->r+1)%q->size;
        q->arr[q->r] = val;
    }
}

//Declearing the function dequeue()
int dequeue(struct queue *q){
    int a = -1;
    if(isEmpty(q)){
        printf("Queue underflow");
    }
    else{
        q->f = (q->f+1)%q->size;
        a = q->arr[q->f];
    }
    return a;
}

//Display the array
void display(struct queue * q){
    if(isEmpty(q)){
        printf("Empty queue");
    }
    else{
        for (int i = q->f+1; i <= q->r; i++)
        {
            printf("%d ",q->arr[i]);
        }
        
    }
}
int main(){
    //Initialize and dynamic memory alloction
    struct queue * q= (struct queue*)malloc(sizeof(struct queue));
    q->f = q->r = 0;
    q->size = 8;
    q->arr = (int*)malloc(q->size*sizeof(int));
    
    //Make a chioce
    int ch;
    do{
        printf("\n____Menu____\nEnter your choice: \n1.Enqueue \n2.Dequeue \n3.Display\n4.Exit_____________________\n\n");
        scanf("%d",&ch);
        switch (ch)
        {
        case 1:
            enqueue(q);
            break;
        case 2:
            printf("Dequed item : %d\n",dequeue(q));
            break;
        case 3:
            display(q);
            break;
        case 4:
            printf("Exiting...");
            break;
        default:
            printf("You give wrong input");
            break;
        }
    }while(ch!= 4);
    free(q->arr);
    return 0;
}