# Write a C program to find the minimum element in an array using dynamic memory allocation.

import array as arr

a = arr.array('i')

n = int(input("Enter the number of elements: "))
for i in range(n):
    val = int(input(f"Enter the element {i+1}: " ))
    a.append(val)

min = 1000000000
for i in range(n):
    if(min> a[i]):
        min =a[i]

print("The minimum element is",min)