# Write a program to print the odd number and even number nodes separately from a
# single linked list.


class node:
    def __init__(self,data):
        self.data =data
        self.next = None

class linkedList:
    def __init__(self):
        self.head = None

    def insert_at_first(self,data):
        new_node = node(data)
        new_node.next = self.head
        self.head = new_node

    def delete_at_first(self):
        if self.head is not None:
            self.head = self.head.next

    def insert_at_last(self,data):
        new_node = node(data)
        if self.head is None:
            self.head = new_node
            return 
        temp = self.head
        while temp.next:
            temp = temp.next
        temp.next = new_node
        new_node.next = None

    def delete_at_last(self):
        if self.head == None:
            print("Empty List")
        if self.head.next == None:
            self.head = None
            return
        temp = self.head
        while temp.next.next:
            temp = temp.next
        temp.next = None
        
    def insert_at_index(self,data,index):
        new_node = node(data)
        i=0
        p = self.head
        if (index == 0):
            new_node.next = self.head
            self.head = new_node
            return
        while p and i< index-1:
            p = p.next
            i+=1

        new_node.next = p.next
        p.next = new_node

    def delete_at_index(self,index):
            if self.head == None:
                print("Empty List")
            i=0
            if index == 0:
                t = self.head
                self.head = self.head.next
                del(t)
                return
            temp = self.head
            while temp and i< index-1:
                temp = temp.next
                i+=1
            temp2 = temp.next
            temp.next = temp2.next
            del(temp2)
        
    def display(self):
        temp = self.head
        while temp:
            print(temp.data,end="-->")
            temp = temp.next
        print("None")

    def print_even_odd(self):
        if self.head == None:
            print("Empty List")
            return 
        else:
            p = self.head 
            print("Even: ")
            while p:
                if p.data%2 == 0:
                    print(p.data,end="-->")
                p = p.next
            print("None\n")

            q = self.head 
            while q:
                if q.data%2 == 0:
                    print(q.data,end="-->")
                q= q.next
            print("None\n")

if __name__ == "__main__":
    n = linkedList()
    ch = 0
    while ch != 8:
        ch = int(input("___MENU___\nEnter the choice\n1.CreateNode at first\n2.CreateNode at last\n3.CreateNode at index\n4.DeleteNode at first\n5.DeleteNode at last\n6.DeleteNode at index\n7.Print Even and odd\n\n"))
        match ch:
            case 1:
                data = int(input("Enter the data: "))
                n.insert_at_first(data)
                n.display()
            case 2:
                data = int(input("Enter the data: "))
                n.insert_at_last(data)
                n.display()
            case 3:
                index = int(input("Enter the index: "))
                data = int(input("Enter the data: "))
                n.insert_at_index(data,index)
                n.display()
            case 4:
                n.delete_at_first()
                n.display()
            case 5:
                n.delete_at_last()
                n.display()
            case 6:
                index = int(input("Enter the index: "))
                n.delete_at_index(index)
                n.display()
            case 7:
                n.print_even_odd()
            case 8:
                print("Exiting...")
        