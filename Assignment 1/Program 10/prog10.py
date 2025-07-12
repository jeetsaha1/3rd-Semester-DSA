#Write a C program to modify the size of an array and utilize that during run time.

import array as arr

a1 = arr.array('i')

n = int(input("Enter the number of elements: "))
for i in range(n):
    val = int(input(f"Enter the element {i+1}: "))
    a1.append(val)

new_size = int(input("Enter the new size: "))
if(new_size>n):
    for j in range(n,new_size):
        val = int(input(f"Enter the element {j+1}: "))
        a1.append(val)

else:
    del a1[new_size:]

print(a1)