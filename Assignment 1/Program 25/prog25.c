//Write a Python program to create a 2D array containing 12 integers. Also print all the members of the array.

#include<stdio.h>
#include<stdlib.h>

int main(){
    int row =3, col =4;
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

    
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    
    free(arr);
    return 0;
}