//Write a Python program to find whether a given array of integers contains any
//duplicate element. Return true if any value appears at least twice in the said

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
        for (int j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j]){
                count+=1;
                break;
            }
            else
                continue;
        }
        
    }
    if(count>0){
        printf("True");
    }
    else    
        printf("False");
        free(arr);
    return 0;
}