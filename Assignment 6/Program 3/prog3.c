// 3. Write a C program to implement Priority Queue.

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define MAX 10

//Making the structure
typedef struct Queue{
    int *data;
    int *priority;
    int size;
}queue;

//IsFull Function
int isFull(queue *q){
    if (q->size == MAX)
        return 1;
    return 0;
}

//IsEmpty Function
int isEmpty(queue *q){
    if(q->size == 0)
        return 1;
    return 0;
}

void enqueue(queue *q, int val, int p){
    if(isFull(q)){
        printf("Queue Overflow");
        return ;
    }
    else{
        q->data[q->size] = val;
        q->priority[q->size] = p;
        q->size ++;
    }
}

int dequeue(queue *q){
    //Base condition
    if (isEmpty(q)){
        printf("Queue underflow");
        return -1;
    }
    //At first We have to find the max. priority
    int idx = 0;
    for (int i = 0; i < q->size; i++)
    {
        if(q->priority[i] < q->priority[idx])
            idx = i;
    }
    int d_ele = q->data[idx];

    //Deleting element by shifting
    for (int i = idx; i < q->size; i++)
    {
        q->data[i] = q->data[i+1];
        q->priority[i] = q->priority[i+1];
    }
    q->size--;
    
    return d_ele;   
}

void display(queue *q){
    if(isEmpty(q))
        return ;
    for (int i = 0; i < q->size; i++)
        printf("(%d,%d)-->",q->data[i],q->priority[i]);
    printf("NULL\n");
}

int main(){
    queue *pq = (queue*)malloc(sizeof(queue));
    pq->size = -1;
    pq->data = (int*)malloc(MAX*sizeof(int));
    pq->priority=(int*)malloc(MAX*sizeof(int));

    enqueue(pq, 10, 2);
    enqueue(pq, 20, 1);
    enqueue(pq, 30, 3);
    enqueue(pq, 40, 2);

    display(pq);

    printf("Dequeued: %d\n", dequeue(pq));
    display(pq);

    printf("Dequeued: %d\n", dequeue(pq));
    display(pq);

    return 0;
}