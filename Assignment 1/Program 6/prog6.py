#Write a C program to find the minimum element in a 2D array in using dynamic memory allocation

import numpy as np

row = int(input("Enter the number of rows : "))
col = int(input("Enter the number of columns: "))

a = list(map(int,input("Enter the elements: ").split()))
mat1 = np.array(a)
mat2 = mat1.reshape(row,col)
print(mat2)

min = 100000000
for i in range(row):
    for j in range(col):
        if mat2[i][j] < min:
            min = mat2[i][j]

print("The minimum element :",min)