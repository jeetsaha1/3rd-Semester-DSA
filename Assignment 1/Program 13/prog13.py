#Write a Python program to reverse the order of the items in the array.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of inputs: "))
for i in range(n):
    val = int(input(f"Enter the value {i+1}: "))
    a1.append(val)

a2 = arr.array('i')
a2 = a1[::-1]
print(a2)