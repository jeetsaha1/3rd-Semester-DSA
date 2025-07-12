//Write a Python program to remove a specified item using the index from an array.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number %d: ",i+1);
        scanf("%d",(arr+i));
    }
    int idx;
    printf("Enter the index for deleting: ");
    scanf("%d",&idx);
    for (int i = idx; i < n-1; i++)
    {
        arr[i] = arr[i+1];
    }
    for (int i = 0; i < n-1; i++)
    {
        printf("%d ",arr[i]);
    }
    free(arr);
    return 0;
}