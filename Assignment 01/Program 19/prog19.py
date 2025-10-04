#Write a Python program to convert an array to an ordinary list with the same items.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

l= list(a1)
print(l)