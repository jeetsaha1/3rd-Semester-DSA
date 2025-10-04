# 4. Write a Python program to calculate factorial with the help of stack.

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
    
def factorial(num):
    s = stack(num+1)
    while num >= 1:
        s.push(num)
        num -=1
    fact = 1
    while not s.isEmpty():
        fact *= s.pop()
    return fact


if __name__ == "__main__":
    num = int(input("Enter the number :"))
    print(factorial(num))