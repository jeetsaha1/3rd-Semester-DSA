# Write a C program to search an element in an Array using dynamic memory allocation.

import array as arr

myArr = arr.array('i')

n = int(input("Enter the number of inputs: "))
for i in range(n):
    val = int(input(f"Enter the element {i+1}:"))
    myArr.append(val)

ele = int(input("Enter the element for searching :"))
for i in range(n):
    if(myArr[i] == ele):
        print("The element is found at index :",i)
