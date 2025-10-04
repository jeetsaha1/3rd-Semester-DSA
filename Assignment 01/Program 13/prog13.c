//Write a Python program to reverse the order of the items in the array.

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
    int *arr1 = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        arr1[i] = arr[n-i-1];
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr1[i]);
    }
    free(arr);
    free(arr1);

    return 0;
}