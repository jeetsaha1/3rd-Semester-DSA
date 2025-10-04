//Write a Python program to remove the first occurrence of a specified element from an array.

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
    int ele;
    printf("Enter the element for deleting: ");
    scanf("%d",&ele);
    int idx;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            idx = i;
            break;
        }
    }
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