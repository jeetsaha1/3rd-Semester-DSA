# Given a stack of boxes in different colors. Write a python function that accepts the stack of boxes and removes those boxes having color other than the primary colors (Red, Green and Blue) from the stack. The removed boxes should be en-queued into a new queue and returned. The original stack should have only the boxes having primary colors and the order must be maintained.
# Perform case sensitive string comparison wherever necessary.
# Note: Consider the queue to be of the same size as that of the original stack.


#Creating the stack for temporary using 
class stack_temp:
    def __init__(self,capacity):
        self.stack_temp = []
        self.capacity = capacity
    
    def push(self,item):
        if len(self.stack_temp) == self.capacity:
            print("Stack Overflow")
        else:
            self.stack_temp.append(item)

    def pop(self):
        if len(self.stack_temp) == 0:
            print("Stack Underflow")
        else:
            return self.stack_temp.pop()
        
    def peek(self):
        if len(self.stack_temp) == 0:
            print("Empty stack")
        else:
            return self.stack_temp[-1]
        
    def is_empty(self):
        return len(self.stack_temp) == 0
    
    def display(self):
        print (self.stack_temp[::-1])


# Creating the main stack for prime colors
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
        
    def peek(self):
        if len(self.stack) == 0:
            print("Empty stack")
        else:
            return self.stack[-1]
        
    def is_empty(self):
        return len(self.stack) == 0

    def display(self):
        print (self.stack)

# Creating the queue for including every theing except prime colors
class queue:
    def __init__(self,capacity):
        self.queue = []
        self.capacity = capacity

    def enqueue (self,item):
        if len(self.queue) == self.capacity:
            print("Queue Overflow")
        else:
            self.queue.append(item)

    def dequeue (self):
        if len(self.queue) == 0:
            print("Queue Underflow")
        else:
            return self.queue.pop(0)
        
    def display(self):
        if len(self.queue) == 0:
            print("Empty Queue")
        else:
            print(self.queue)


#Initialize the classes
s_temp = stack_temp(10)
s = stack(10)
q = queue(10)

#Input the colors from the user
l = int(input("Enter the no. of elements: "))
color_list1 = []
color_list2 = []
for i in range (l):
    str = input("Enter the color: ")
    color_list1.append(str.lower())

color_list2 = color_list1[:]  # Keep original case

#Pushing the color names into the main stack
for j in range(l):
    s.push(color_list2[j])

prime_list = ["red","green","blue"]     # Making the prime color list for notation

# If the element from main stack satisfies the prime colors then push it in temp_stack
# Or insert the element in queue

while not s.is_empty():
    if s.peek() in prime_list:
        s_temp.push(s.pop())
    else:
        q.enqueue(s.pop())

#Insert the prime colors in the main stack again
while not s_temp.is_empty():
    s.push(s_temp.pop())

# Display the result
print("Prime colors are: ")
s.display()
print("\n\nThe colors except prime colors are: ")
q.display()