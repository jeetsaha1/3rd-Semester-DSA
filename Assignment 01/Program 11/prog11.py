#Write a Python program to create an array of 5 integers and display the array items. Access individual elements through indexes.

import array as arr

a1 = arr.array('i')
for i in range(5):
    val = int(input("Enter the element: "))
    a1.append(val)

for i in range(5):
    print(a1[i],end=' ')