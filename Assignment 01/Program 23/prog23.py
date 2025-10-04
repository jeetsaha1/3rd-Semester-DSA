#Write a Python program to remove all duplicate elements from a given array and returns a new array.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

a2= arr.array('i')

for ele in a1:
    if ele in a2:
        continue
    else:
        a2.append(ele)
print(a2)