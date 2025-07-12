//Write a Python program to get the number of occurrences of a specified element in an array.

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

    int ele, count = 0;
    printf("Enter the no. for counting occurences: ");
    scanf("%d",&ele);
    for (int i = 0; i < n; i++)
    {
        if(arr[i] == ele)
            count++;
    }

    printf("The no. of occurences of %d is %d.",ele,count);
    free(arr);
    
    return 0;
}