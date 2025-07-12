//Write a Python program to remove all duplicate elements from a given array and returns a new array.

#include<stdio.h>

int main(){
    int n;
    printf("Enter the number of elements : ");
    scanf("%d",&n);

    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d : ",i+1);
        scanf("%d",&arr[i]);
    }
    
    //Remove duplicate elements
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j; k < n; k++)
                {
                    arr[k] = arr[k+1];  //shift the element to the left
                }
                n--;
                j--;
            }
            
        }
        
    }

    for (int l = 0; l < n; l++)
    {
        printf("%d ",arr[l]);
    }
    
    
    return 0;
}