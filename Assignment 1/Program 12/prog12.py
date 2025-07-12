#Write a Python program to append a new item to the end of the array.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the number of inputs: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

new_ele = int(input("Enter the new element : "))
a1.append(new_ele)
n+=1
for i in range(n):
    print(a1[i],end=' ')