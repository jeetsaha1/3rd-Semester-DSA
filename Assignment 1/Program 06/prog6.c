//Write a C program to find the minimum element in a 2D array in using dynamic memory allocation

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
    int row,col;
    printf("Enter the no. of row and column respectively: ");
    scanf("%d %d",&row,&col);
    
    int **arr = (int**)malloc(row*sizeof(int*));

    for (int i = 0; i < row; i++)
    {
        arr[i] = (int*)malloc(col*sizeof(int));
    }
    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("Enter the element [%d][%d]:",i+1,j+1);
            scanf("%d",&arr[i][j]);
        }
    }

    int min = INT_MAX;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(arr[i][j]< min)
                min = arr[i][j];
        }
        
    }
    printf("The maximum element is: %d",min);
    free(arr);
    return 0;
}