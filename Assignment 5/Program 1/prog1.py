# Write a python program to create a Double linked list along with the following functions:
#    a) to display the elements of a Double Linked List.
#    b) to add an element at beginning of a Double linked list.
#    c) to add an element at the end of a Double linked list.
#    d) to add an element at any user given position of a Double linked list.
#    e) to search a user given element in a Double linked list.
#    f) to count the number of nodes in a Double linked list.
#    g) to delete a node at beginning of a Double linked list.
#    h) to delete a node at end of a Double linked list.
#    i) to delete a node from any position of a Double linked list.
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
                newNode.next = None
            ch = int(input("Do you want to insert(1/0): "))

    # a.To display element from linked list
    def displayList(self):
        temp = self.head
        while temp.next:
            print(temp.data,end="-->")
            temp = temp.next
        print(temp.data,end="-->None\n")

    # b.Add element at beginning
    def insert_at_begining(self,val):
        newNode = node(val)
        if self.head is None:
            self.head = newNode
        else:
            newNode.next = self.head
            self.head.prev = newNode
            self.head = newNode

    # c.Add element at ending
    def insert_at_end(self,val):
        newNode = node(val)
        if self.head is None:
            self.head = newNode
        else:
            tail = self.head
            while tail.next != None:
                tail = tail.next
            tail.next = newNode
            newNode.prev = tail
            tail = newNode
            newNode.next = None

    # d.Add element at any position
    def insert_at_any(self,val,index):
        newNode = node(val)
        if index == 0:
            return self.insert_at_begining(val)
        else:
            tail = self.head
            i = 0
            while tail.next is not None and i<index-1:
                tail = tail.next
                i += 1
            if tail.next == None:
                tail.next = newNode
                newNode.prev = tail
            else:
                newNode.next = tail.next
                tail.next.prev = newNode
                tail.next = newNode
                newNode.prev = tail

    #e.searching a user given element
    def searching_element(self,ele):
        f,i = 0,0
        if self.head is None:
            return 0
        else:
            temp = self.head
            while temp:
                if temp.data == ele:
                    f = i
                    break
                i +=1
                temp = temp.next
        return f
    
    #f.counting the node
    def count_nodes(self):
        count = 0
        if self.head is None:
            return 0
        else:
            temp = self.head
            while temp:
                count += 1
                temp = temp.next
        return count
    
    #g.deleting the node from the begining
    def delete_from_begining(self):
        temp = self.head
        self.head = self.head.next
        temp.next = None
        self.head.prev = None

    # deleting the node from the ending 
    def delete_from_end(self):
        if self.head is None:
            return None
        else:
            temp = self.head
            while temp.next is not None:
                temp = temp.next
            temp.prev.next = None
            temp.prev = None

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
            if tail.prev != None:
                tail.prev.next = tail.next
            if tail.next != None:
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
            
