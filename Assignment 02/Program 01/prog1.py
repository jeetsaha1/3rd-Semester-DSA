#Write a C program to implement stack using dynamic array and perform the following operation • PUSH() • POP() • PEEK() • DISPLAY().

class stack:
    def __init__(self, capacity):
        self.stack= []
        self.capacity  = capacity

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

    def peek(self):
        if len(self.stack) == 0:
            print("Empty stack")
        else:
            return self.stack[-1]
        
    def display(self):
        print (self.stack[::-1])


s = stack(5)

n=0
while n!= 5:
    n = int(input("Enter the choice:\n1.Push\n2.Pop\n3.Peek\n4.Display\n5.Exit\n"))
    match n:
        case 1:
            val = int(input("Enter the number: "))
            s.push(val)
            
        case 2:
            print("Poped element:",s.pop())
        case 3:
            print("The top most value of the stack:",s.peek())
        case 4:
            s.display()
    print("Exiting...")
        

