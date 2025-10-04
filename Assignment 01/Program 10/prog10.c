//Write a C program to modify the size of an array and utilize that during run time.

#include<stdio.h>
#include<stdlib.h>

void initialize(int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

void display(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

int main(){
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    initialize(arr,n);
    display(arr,n);
    int new_size ;
    printf("Enter the new size: ");
    scanf("%d",&new_size);
    arr = (int*)realloc(arr,new_size*sizeof(int));
    if(new_size<n){
        printf("Memory allocation failed");
        return 0;
    }
    for (int i = n; i < new_size; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
    display(arr,new_size);
    free(arr);
    return 0;
}