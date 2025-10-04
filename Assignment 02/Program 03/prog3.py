# Write a C program to reverse a string using appropriate ADT.

class stack:
    def __init__(self,capacity):
        self.stack = []
        self.capacity = capacity
    
    def push(self,item):
        if len(self.stack) == self.capacity:
            print("Stack Overflow")
        else:
            self.stack.append(item)

    def pop(self):
        if len(self.stack) == 0:
            print("Stack Underflow")
        else:
            return self.stack.pop()

str = input("Enter the string: ")

s= stack(len(str))

for ele in str:
    s.push(ele)

for i in range(len(str)):
    print(s.pop(),end="")
