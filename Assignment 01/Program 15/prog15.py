#Write a Python program to create an array containing six integers. Also, print all the members of the array.


import array as arr

a1 = arr.array('i')
n = 6
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

for i in range(n):
    print(a1[i],end=' ')