# Write a Python program to remove the first occurrence of a specified element from an array.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

ele = int(input("Enter the element for deleting: "))
for j in range (n):
    if a1[j] == ele:
        del a1[j]
        break
print(a1)