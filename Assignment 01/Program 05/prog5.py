#Write a C program to find the maximum element in a 2D array in using dynamic memory allocation

import numpy as np

row = int(input("Enter the number of rows : "))
col = int(input("Enter the number of columns: "))

a = list(map(int,input("Enter the elements: ").split()))
mat1 = np.array(a)
mat2 = mat1.reshape(row,col)
print(mat2)

max = 0
for i in range(row):
    for j in range(col):
        if mat2[i][j] > max:
            max = mat2[i][j]

print("The maximum element :",max)