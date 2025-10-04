#Write a Python program to get the length of an array.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

count = 0
for i in range(n):
    count+=1
print("The length of the array is :",count)