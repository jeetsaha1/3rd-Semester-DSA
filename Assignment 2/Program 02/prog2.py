# Write a C program to implement queue using dynamic array. Execute all the   necessary functions of queue.

class queue:
    def __init__(self,capacity):
        self.queue = []
        self.capacity = capacity

    def enqueue(self,item):
        if len(self.queue) == self.capacity:
            print("Queue Overflow")
        else:
            self.queue.append(item)

    def dequeue(self):
        if len(self.queue) == 0:
            print("Queue Underflow")
        else:
            return self.queue.pop(0)
        
    def display(self):
        if len(self.queue) == 0:
            print("Empty Queue")
        else:
            print(self.queue)

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
    print("Exiting...")
        

