# Write a python program to create a Double Circular linked list along with the following functions:
#    a) to display the elements of a Double Circular Linked List.
#    b) to add an element at beginning of a Double Circular linked list.
#    c) to add an element at the end of a Double Circular linked list.
#    d) to add an element at any user given position of a Double Circular linked list.
#    e) to search a user given element in a Double Circular linked list.
#    f) to count the number of nodes in a Double Circular linked list.
#    g) to delete a node at beginning of a Double Circular linked list.
#    h) to delete a node at end of a Double Circular linked list.
#    i) to delete a node from any position of a Double Circular linked list.
#    (Create a menu bar for accessing the functions)



#Create a class for creating a node
class node:
    def __init__(self,data):
        self.data = data
        self.prev = None
        self.next = None

# Main class for creating linked list
class doubleLinkedList:
    def __init__(self):
        self.head = None
        self.tail = None

    # For creating list
    def createList(self):
        ch = -1
        while ch != 0:
            data = int(input("Enter the data: "))
            newNode = node(data)
            if self.head == None:
                self.head = newNode
                self.tail = newNode
            else:
                self.tail.next = newNode
                newNode.prev = self.tail
                self.tail = newNode
                self.tail.next = self.head
                self.head.prev = self.tail

            ch = int(input("Do you want to insert(1/0): "))

    # a.To display element from linked list
    def displayList(self):
        if self.head is None:
            return None
        temp = self.head
        while temp.next != self.head:
            print(temp.data,end="-->")
            temp = temp.next
        print(temp.data,end="-->None\n")

    # b.Add element at beginning
    def insert_at_begining(self,val):
        newNode = node(val)
        if self.head is None:
            self.head = newNode
            newNode.prev = newNode
            newNode.next = newNode
        else:
            newNode.next = self.head
            newNode.prev = self.head.prev
            self.head.prev.next = newNode
            self.head.prev = newNode
            self.head = newNode

    # c.Add element at ending
    def insert_at_end(self,val):
        newNode = node(val)
        if self.head is None:
            self.head = newNode
        else:
            tail = self.head.prev
            tail.next = newNode
            newNode.prev = tail
            newNode.next = self.head
            self.head.prev = newNode

    # d.Add element at any position
    def insert_at_any(self,val,index):
        newNode = node(val)
        if index == 0:
            return self.insert_at_begining(val)
        else:
            tail = self.head
            i = 0
            while tail.next is not self.head and i<index-1:
                tail = tail.next
                i += 1
            newNode.next = tail.next
            tail.next.prev = newNode
            tail.next = newNode
            newNode.prev = tail

    #e.searching a user given element
    def searching_element(self,ele):
        f,i = 0,0
        temp = self.head
        if self.head is None:
            return -1
        else:
            while temp.next != self.head:
                if temp.data == ele:
                    return i
                i +=1
                temp = temp.next
        return -1
    
    #f.counting the node
    def count_nodes(self):
        count = 0
        if self.head is None:
            return 0
        else:
            temp = self.head
            while True:
                count += 1
                temp = temp.next
                if temp == self.head:
                    break
        return count
    
    #g.deleting the node from the begining
    def delete_from_begining(self):
        if self.head.next == self.head:
            self.head =  None
            return
        temp = self.head
        self.head = self.head.next
        self.head.prev = temp.prev
        temp.prev.next = self.head
        del temp

    # deleting the node from the ending 
    def delete_from_end(self):
        tail = self.head.prev
        if self.head is None:
            return None
        else:
            tail.prev.next = self.head
            self.head.prev = tail.prev
            

    # Deleting the node from any position
    def delete_from_any(self,index):
        if self.head is None:
            return None
        if index == 0:
            return self.delete_from_begining()
        else:
            tail = self.head
            i = 0
            while tail is not None and i< index:
                tail = tail.next
                i +=1
            tail.prev.next = tail.next
            tail.next.prev = tail.prev

if __name__ == "__main__":
    l = doubleLinkedList()
    ch = -1
    while ch != 11:
        ch = int(input("___MENU___\nEnter the choice\n1.Create list\n2.Display List\n3.Insert at first\n4.Insert at last\n5.Insert at any\n6.Search element\n7.Count element\n8.Delete from first\n9.Delete from last\n10.Delete from any\n\n"))
        match (ch):
            case 1:
                l.createList()
            case 2:
                l.displayList()
            case 3:
                data = int(input("Enter the number: "))
                l.insert_at_begining(data)
            case 4:
                data = int(input("Enter the number: "))
                l.insert_at_end(data)
            case 5:
                data = int(input("Enter the number: "))
                index = int(input("Enter the index number: "))
                l.insert_at_any(data,index)
            case 6:
                ele = int(input("Enter the number for serching: "))
                if l.searching_element(ele) != 0:
                    print("The element is found at node no.",l.searching_element(ele))
            case 7:
                print("The total no. of nodes:",l.count_nodes())
            case 8:
                l.delete_from_begining()
            case 9:
                l.delete_from_end()
            case 10:
                index = int(input("Emter the index no: "))
                l.delete_from_any(index)
            case 11:
                print("Exiting...")
            
