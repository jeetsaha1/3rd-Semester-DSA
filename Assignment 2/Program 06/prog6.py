# Write a Python program to implement queue using stack

class stack1 :
    def __init__(self,capacity):
        self.stack1 = []
        self.capacity = capacity
    
    def push (self,item):
        if len(self.stack1) == self.capacity:
            print("Stack overflow")
            return None
        else:
            self.stack1.append(item)

    def pop (self):
        if len(self.stack1) == 0:
            print("Stack underflow")
            return None
        else:
            return self.stack1.pop()
        
    def display(self):
        if len(self.stack1) == 0:
            print("Empty Stack")
            return None
        else:
            print(self.stack1[::-1])



class stack2 :
    def __init__(self,capacity):
        self.stack2 = []
        self.capacity = capacity
    
    def push (self,item):
        if len(self.stack2) == self.capacity:
            print("Stack overflow")
            return None
        else:
            self.stack2.append(item)

    def pop (self):
        if len(self.stack2) == 0:
            print("Stack underflow")
            return None
        else:
            return self.stack2.pop()
        
    def display(self):
        if len(self.stack2) == 0:
            print("Empty Stack")
            return None
        else:
            print(self.stack2[::-1])



class queue:
    def __init__(self,capacity):
        self.capacity = capacity
        self.stack1 = stack1(10)
        self.stack2 = stack2(10)

    def enqueue (self,item):
        if len(self.stack1.stack1) == self.capacity:
            print("Queue Overflow")
            return None
        else:
            self.stack1.push(item)

    def dequeue (self):
        if len(self.stack2.stack2) == 0 and len(self.stack1.stack1) == 0:
            print("Queue Underflow")
            return None
        if len(self.stack2.stack2) == 0:
            while (len(self.stack1.stack1) != 0):
                self.stack2.push(self.stack1.pop())
        return self.stack2.pop()
    
    def display(self):
        print(self.stack2.stack2[::-1])
        print(self.stack1.stack1)

q = queue(10)
n=0
while n!= 4:
    n = int(input("Enter the choice:\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n\n"))
    match n:
        case 1:
            val = int(input("Enter the number: "))
            q.enqueue(val)
        case 2:
            print("Poped element:",q.dequeue())
        case 3:
            q.display()
        case 4:
            print("Exiting...")
        
