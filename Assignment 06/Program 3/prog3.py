# 3. Write a Python program to implement Priority Queue.

class P_Queue:
    def __init__(self,capacity):
        self.data= []
        self.priority = []
        self.capacity = capacity
        
    def isFull(self):
        if len(self.data) == self.capacity:
            return 1
        return 0
    
    def enqueue(self, data, priority):
        if self.isFull():
            print("Queue Overflow")
        else:
            self.data.append(data)
            self.priority.append(priority)

    def dequeue(self):
        # Checking which prority is max. in the queue
        idx = 0
        for i in range(0,len(self.data)):
            if(self.priority[idx] < self.priority[i]):
                idx = i
        
        d_ele = self.data[idx]
        d_p = self.priority[idx]

        self.data.remove(d_ele)
        self.priority.remove(d_p)

    def display(self):
        for i in range(0,len(self.data)):
            print(f"{(self.data[i],self.priority[i])}",end="->")
        print("None")

pq = P_Queue(10)

pq.enqueue( 10, 2)
pq.enqueue( 20, 1)
pq.enqueue( 30, 3)
pq.enqueue( 40, 2)

pq.display()
print(pq.dequeue())
pq.display()