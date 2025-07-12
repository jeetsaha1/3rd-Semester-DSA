//Write a Python program to get the length of an array.

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
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        count++;
    }
    printf("The length of the array is : %d",count);
    free(arr);
    return 0;
}