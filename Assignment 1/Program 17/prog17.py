#Write a Python program to remove a specified item using the index from an array.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

idx = int(input("Enter the idx for deleting: "))
for j in range (n):
    if j == idx:
        del a1[j]
print(a1)