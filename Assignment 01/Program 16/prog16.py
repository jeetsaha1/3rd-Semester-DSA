#Write a Python program to insert a new item before the second element in an existing array.


import array as arr

a1 = arr.array('i')
n = int(input("Enter the no. of elements: "))
for i in range(n):
    val = int(input("Enter the element: "))
    a1.append(val)

new_ele = int(input("Enter the new element: "))
a1.insert(1,new_ele)
print(a1)