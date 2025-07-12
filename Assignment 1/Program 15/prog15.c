//Write a Python program to create an array containing six integers. Also, print all the members of the array.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int n=6;
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