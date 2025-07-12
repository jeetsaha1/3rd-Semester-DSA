# Write a C program to find the 3 rd /user defined position based maximum element in an array using dynamic memory allocation.

import array as arr

def bubble_sort(arr,n):
    for i in range(0,n):
        for j in range(0,n-i-1):
            if arr[j] < arr[j+1]:
                t = arr[j]
                arr[j] = arr[j+1]
                arr[j+1] = t


a = arr.array('i')

n = int(input("Enter the number of inputs:"))
for i in range(n):
    val = int(input(f"Enter the element {i+1}:"))
    a.append(val)

bubble_sort(a,n)

print("The 3rd position of the array based on the maximum element :",a[3])