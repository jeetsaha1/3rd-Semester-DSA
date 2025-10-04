#  6. Write a Python program to reverse a string using stack.

class stack:
    def __init__(self,capacity):
        self.stack = []
        self.capacity = capacity
    
    def isEmpty(self):
        if len(self.stack) == 0:
            return 1
        return 0

    def push(self, val):
        if len(self.stack) == self.capacity:
            print("Stack Overflow")
        else:
            self.stack.append(val)
    
    def pop(self):
        if len(self.stack) == 0:
            print("Stack Underflow")
        else:
            return self.stack.pop()
        
def reverse(string):
    s = stack(len(string))
    for i in range(0,len(string)):
        s.push(string[i])
    
    while not s.isEmpty():
        print(s.pop(),end="")

string = input("Enter the string: ")
reverse(string)