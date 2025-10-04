# Write a C program to store polynomial using linked list. Store the term in ascending
# order.

class node:
    def __init__(self,coefficient,power):
        self.coefficient = coefficient
        self.power = power
        self.next = None
    
class linkedList:
    def __init__(self):
        self.head = None
    
    def createNode(self,coefficient,power):
        new_node = node(coefficient,power)

        if self.head == None or power < self.head.power:
            new_node.next = self.head
            self.head = new_node
        else:
            p = self.head
            while p.next != None and p.next.power <power:
                p = p.next
            new_node.next = p.next
            p.next = new_node

    def display(self):
        p =  self.head
        while p :
            print(f"{p.coefficient}x^{p.power}", end=" + ")
            p = p.next
        print("None")


if __name__ == "__main__":
    poly = linkedList()

    ch = -1
    while(ch != 0):
        coef = int(input("Enter the coffecient: "))
        power = int(input("Enter the power: "))
        poly.createNode(coef,power)
        ch = int(input("Do you want to innsert: "))
    poly.display()