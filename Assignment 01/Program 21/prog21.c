//Write a Python program to find a pair with the highest product from a given array of integers.

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
    int mul = 0, c=arr[0],d = arr[1];
    int max = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            mul = arr[i]*arr[j];
            if(max<mul){
                max = mul;
                c = arr[i];
                d = arr[j];
            }
        }
        
    }
    printf("(%d, %d)",c,d);
    free(arr);
    return 0;
}