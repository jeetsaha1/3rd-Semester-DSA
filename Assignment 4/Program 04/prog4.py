# Write a program to perform addition of two polynomials using linked list.

class node:
    def __init__(self,coeff,power):
        self.coefficient = coeff
        self.power = power
        self.next = None

class linkedList:
    def __init__(self):
        self.head = None

    def createNode(self):
        ch = -1
        while ch !=0:
            coeff = int(input("Enter the coefficient : "))
            power = int(input("Enter the power : "))
            newNode = node(coeff,power)

            if self.head is None:
                self.head = newNode
            else:
                p = self.head
                while p.next:
                    p = p.next
                p.next = newNode
                newNode.next = None
            ch = int(input("Do you want to insert(1/0): "))


    def createNode_res(self,coeff, power):
        newNode = node(coeff,power)

        if self.head is None:
            self.head = newNode
        p = self.head
        while p.next:
            p = p.next
        p.next = newNode
        newNode.next = None

    def displayList(self):
        temp = self.head
        while temp :
            print(f"{temp.coefficient}x^({temp.power})",end="+")
            temp = temp.next
        print("0\n")

if __name__ == "__main__":
    l1 = linkedList()
    l1.createNode()
    l1.displayList()

    l2 = linkedList()
    l2.createNode()
    l2.displayList()
    
    l3 = linkedList()
    p = l1.head
    q = l2.head
    while p is not None and q is not None:
        if p.power == q.power:
            sum = p.coefficient + q.coefficient
            l3.createNode_res(sum,p.power)
            p = p.next
            q = q.next
        elif p.power > q.power:
            l3.createNode_res(p.coefficient,p.power)
            p = p.next
        else:
            l3.createNode_res(q.coefficient,q.power)
            q = q.next
        
    while p:
        l3.createNode_res(p.coefficient, p.power)
        p = p.next

    while q:
        l3.createNode_res(q.coefficient, q.power)
        q = q.next

    l3.displayList()