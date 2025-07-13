//Write a C program to merge two sorted dynamic array

#include<stdio.h>
#include<stdlib.h>

void initialize (int *arr,int n){
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ",i+1);
        scanf("%d",&arr[i]);
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
    
    int *sorted_arr = (int*)malloc((n+m)*sizeof(int));
    int k = 0,l = 0,d=0;
    while (d < m && l < n)
    {
        if(arr1[d] < arr2[l]){
            sorted_arr[k++] = arr1[d++];
        }
        else{
            sorted_arr[k++] = arr2[l++];
        }
    }
    
    while (d < m)
    {
        sorted_arr[k++] = arr1[d++];
    }

    while (l < n)
    {
        sorted_arr[k++] = arr2[l++];
    }
    
    

    for (int i = 0; i < k; i++)
    {
        printf("%d ",sorted_arr[i]);
    }
    
    free(arr1);
    free(arr2);
    free(sorted_arr);
    return 0;
}