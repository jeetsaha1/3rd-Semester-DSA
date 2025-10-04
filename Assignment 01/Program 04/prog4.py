#Write a C program to search an element in a 2D-Array using dynamic memory allocation.

import numpy as np

row = int(input("Enter the number of rows : "))
col = int(input("Enter the number of columns: "))

a = list(map(int,input("Enter the elements: ").split()))
mat1 = np.array(a)
mat2 = mat1.reshape(row,col)
print(mat2)

ele = int(input("Enter the element for searching: "))
for i in range(row):
    for j in range(col):
        if mat2[i][j] == ele:
            print("The element is found at index :",(i,j))