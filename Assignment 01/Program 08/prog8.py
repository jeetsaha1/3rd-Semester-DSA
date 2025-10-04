# Write a C program to merge two unsorted dynamic array in sorted order.

def bubble_sort(a3,n):
    for i in range(n):
        for j in range(n-i-1):
            if(a3[j]>a3[j+1]):
                t = a3[j]
                a3[j] = a3[j+1]
                a3[j+1] = t

import array as arr

a1 = arr.array('i')
n = int(input("Enter the number of inputs: "))
for i in range(n):
    val = int(input(f"Enter the element{i+1}: "))
    a1.append(val)

a2 = arr.array('i')
m = int(input("Enter the number of inputs: "))
for i in range(m):
    val = int(input(f"Enter the element{i+1}: "))
    a2.append(val)

a3 = arr.array('i')
for i in range(n):
    a3.append(a1[i])

for j in range(m):
    a3.append(a2[j])

bubble_sort(a3,(n+m))


print(a3)