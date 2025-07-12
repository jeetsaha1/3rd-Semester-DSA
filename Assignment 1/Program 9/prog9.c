// Write a C program to delete a range of data from a dynamic array.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }

    int start,end ;
    printf("Enter the ranges(start, end): ");
    scanf("%d %d",&start, &end);

    int newsize = n-(end-start+1);
    for (int i = end+1; i < n; i++)
    {
        arr[start++] = arr[i];
    }
    
    arr = (int*)realloc(arr,newsize*sizeof(int));

    for (int i = 0; i < newsize; i++)
    {
        printf("%d ",arr[i]);
    }    
    free(arr);
    return 0;
}