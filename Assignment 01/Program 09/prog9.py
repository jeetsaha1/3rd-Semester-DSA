#Write a C program to delete a range of data from a dynamic array.

import array as arr

a1 = arr.array('i')
n = int(input("Enter the number of inputs: "))
for i in range(n):
    val = int(input(f"Enter the element{i+1}: "))
    a1.append(val)

start = int(input("Enter the start range: "))
end = int(input("Enter the end range: "))
new_idx = end-start+1
for i in range(end+1,n):
    a1[start] = a1[i]
    start+=1

del a1[n-new_idx:]
print(a1)