#Write a Python program to find a pair with the highest product from a given array of integers.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)
max = 0
c=a1[0]
d=a1[1]
for j in range(n):
    for k in range(j+1,n):
        product = a1[j]*a1[k]
        if max< product:
            max = product
            c = a1[j]
            d = a1[k]

print(f"{c},{d}")
        