// Write a C program to find the minimum element in an array using dynamic memory allocation.

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int *ptr;
    ptr = (int *)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",(ptr+i));
    }
    
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        if(min> ptr[i])
            min = ptr[i];
    }

    printf("The minimum element is: %d",min);
    free(ptr);
    return 0;
}