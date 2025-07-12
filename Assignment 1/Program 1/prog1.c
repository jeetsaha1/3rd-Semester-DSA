// Write a C program to search an element in an Array using dynamic memory allocation.

#include<stdio.h>
#include<stdlib.h>

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
    
    int ele;
    printf("Enter the element for searching: ");
    scanf("%d",&ele);

    for (int j = 0; j < n; j++)
    {
        if(ptr[j] == ele)
            printf("The element is found at index: %d",j);
    }
    free(ptr);

    
    return 0;
}