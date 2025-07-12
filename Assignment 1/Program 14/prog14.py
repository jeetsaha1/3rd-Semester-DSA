#Write a Python program to get the number of occurrences of a specified element in an array.

import array as arr

a1 = arr.array('i')

n = int(input("Enter the number of inputs: "))
for i in range(n):
    val = int(input(f"Enter the element {i+1}: "))
    a1.append(val)
count = 0
ele = int(input("Enter the number for counting occurences: "))
for j in range(n):
    if a1[j] == ele:
        count+=1

print(f"The no. of occurences of {ele} is {count}")