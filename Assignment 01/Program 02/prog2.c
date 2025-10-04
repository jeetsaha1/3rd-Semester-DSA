// Write a C program to find the 3 rd /user defined position based maximum element in an array using dynamic memory allocation.

#include<stdio.h>
#include<stdlib.h>

void bubble_sort(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
        
    }
    
}
int main(){
    int n;
    printf("Enter the number of inputs: ");
    scanf("%d",&n);
    int *arr;
    arr = (int*)malloc(n*sizeof(int));
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d:",i+1);
        scanf("%d",(arr+i));
    }
    bubble_sort(arr,n);
    
    // for (int i = 0; i < n; i++)
    // {
    //     printf("%d ",*(arr+i));
    // }
    printf("The 3rd user defined position of the array based on max. element: %d",arr[3]);

    free(arr);
    return 0;
}