#Write a C program to merge two sorted dynamic array

import array as arr

n = int(input("Enter the no. of inputs of first array: "))
a1 = arr.array('i')
for i in range(n):
    val = int(input(f"Enter the element {i+1}:"))
    a1.append(val)

m = int(input("Enter the no. of inputs of second array: "))
a2 = arr.array('i')
for j in range(n):
    val = int(input(f"Enter the element {j+1}:"))
    a2.append(val)

a3 = arr.array('i')
l,d = 0,0

while l<len(a1) and d<len(a2):
    if a1[l] < a2[d]:
        a3.append(a1[l])
        l+=1
    else:
        a3.append(a2[d])
        d+=1

while l<len(a1):
    a3.append(a1[l])
    l+=1

while d<len(a2):
    a3.append(a2[d])
    d+=1

print(a3)