# Write a Python program to implement circular queue using array.

class queue:
    def __init__(self,size):
        self.size = size
        self.front = -1
        self.rear = -1
        self.queue = [None]*size

    def enqueue(self,item):
        if (self.rear+1)%self.size == self.front:
            print("Queue Overflow")
            return
        if self.front == -1:  
            self.front = 0
            self.rear = 0
        else:
            self.rear = (self.rear+1)%self.size
        self.queue[self.rear] = item

    def dequeue (self):
        if self.front== -1:
            print("Queue Underflow")
            return
        data = self.queue[self.front]
        if self.front == self.rear:
            self.front = -1
            self.rear = -1
        else:
            self.front = (self.front+1)%self.size
        return data
    
    def display (self):
        if self.front == -1:
            print("Empty Queue")
        else:
            i = self.front
            while True:
                print(self.queue[i],end= " ")
                if i == self.rear:
                    break
                i = (i+1)%self.size
      

q = queue(5)

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
    
        
