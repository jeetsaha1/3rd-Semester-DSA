#Write a Python program to create a 2D array containing 12 integers. Also print all the members of the array.

import numpy as np

arr = list(map(int,input("Enter the numbers : ").split()))
mat1 = np.array(arr)
mat2 = mat1.reshape(3,4)
print(mat2)