//Write a Python program to append a new item to the end of the array.

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

    int new_ele;
    printf("Enter the new element: ");
    scanf("%d",&new_ele);

    arr = (int*)realloc(arr,(n+1)*sizeof(int));
    arr[n] = new_ele;

    for (int i = 0; i < n+1; i++)
    {
        printf("%d ",*(arr+i));
    }
    free(arr);
    return 0;
}