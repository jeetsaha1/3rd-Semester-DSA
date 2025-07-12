#Write a Python program to find whether a given array of integers contains any
#duplicate element. Return true if any value appears at least twice in the said

import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

unique_set = set()
f = 0

for ele in a1:
    if ele in unique_set:
        f=1
        break
    else:
        unique_set.add(ele)
    

if f==1:
    print("True")
else:
    print("False")