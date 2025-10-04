//Write a Python program to insert a new item before the second element in an existing array.

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
    printf("Enter the new element : ");
    scanf("%d",&new_ele);

    arr = (int*)realloc(arr,(n+1)*sizeof(int));

    for (int i = n; i > 1; i--)
    {
        arr[i] = arr[i-1];
    }
    arr[1] = new_ele;
    n+=1;
    for (int i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }

    free(arr);
        
    return 0;
}