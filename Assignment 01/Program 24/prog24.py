#Write a Python program to find the missing number in a given array of numbers between 10 and 20.

import array as arr

a1 = arr.array('i')
n = 20
for i in range(11,20):
    val = int(input("Enter the element: "))
    a1.append(val)

actual_output = sum(range(11,21))
expected_output =sum(a1)

num = actual_output-expected_output
print(num)