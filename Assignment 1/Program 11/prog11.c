//Write a Python program to create an array of 5 integers and display the array items. Access individual elements through indexes.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int *arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the number %d",i+1);
        scanf("%d",(arr+i));
    }
    for (int i = 0; i < n; i++)
    {
        printf("%d ",*(arr+i));
    }
    free(arr);
    return 0;
}