// Write a C program to merge two unsorted dynamic array in sorted order.

#include<stdio.h>
#include<stdlib.h>

void initialize (int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
    }
}

void bubble_sort(int *arr, int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n-i-1; j++)
        {
            if(arr[j]>arr[j+1]){
                int t = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = t;
            }
        }
        
    }
    
}
int main(){
    int n ,m;
    printf("Enter the number of inputs for first array: ");
    scanf("%d",&n);
    int *arr1 = (int*)malloc(n*sizeof(int));
    initialize (arr1,n);


    printf("Enter the number of inputs for second array: ");
    scanf("%d",&m);
    int *arr2 = (int*)malloc(m*sizeof(int));
    initialize (arr2,m);
    
    int *new_arr = (int*)malloc((n+m)*sizeof(int));
    for (int k = 0; k < n; k++)
    {
        new_arr[k] = arr1[k];
    }
    for (int k = n,i=0; k < n+m; k++,i++)
    {
        new_arr[k] = arr2[i];
    }

    bubble_sort(new_arr,(n+m));

    for (int i = 0; i < n+m; i++)
    {
        printf("%d ",new_arr[i]);
    }
    
    free(arr1);
    free(arr2);

    return 0;
}