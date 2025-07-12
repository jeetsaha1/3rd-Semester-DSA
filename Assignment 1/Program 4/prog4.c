//Write a C program to search an element in a 2D-Array using dynamic memory allocation.

#include<stdio.h>
#include<stdlib.h>

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

    int ele ;
    printf("Enter the number of searching: ");
    scanf("%d",&ele);

    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            if(arr[i][j] == ele)
                printf("The element is found at index: (%d,%d)",i,j);
        }
        
    }
    free(arr);
    
    return 0;
}