# Write a program to merge two already sorted list

class node:
    def __init__(self,data):
        self.data = data
        self.next = None
    
class linkedList:
    def __init__(self):
        self.head = None

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

    def delete_at_first(self):
        if self.head is not None:
            self.head = self.head.next


    def display(self):
        temp = self.head
        while temp:
            print(temp.data,end="-->")
            temp = temp.next
        print("None")

    

def merge_sorted_list(head1,head2):
        head3 = None
        tail = None
        if head1 is None:
            return head2
        if head2 is None:
            return head1
        
        if head1.data < head2.data:
            head3 = head1
            tail = head1
            head1 = head1.next
        else:
            head3 = head2
            tail = head2
            head2 = head2.next
        
        while head1 and head2:
            if head1.data < head2.data:
                tail.next = head1
                tail = head1
                head1 = head1.next
            else:
                tail.next = head2
                tail = head2
                head2 = head2.next

        # Attach remaining part
        if head1:
            tail.next = head1
        else:
            tail.next = head2

        return head3

if __name__ == "__main__":
    l1 = linkedList()
    l2 = linkedList()
    for val in [1, 3, 5]:
        l1.insert_at_last(val)
    for val in [2, 4, 6]:
        l2.insert_at_last(val)

    merged_head = merge_sorted_list(l1.head, l2.head)

    merged_list = linkedList()
    merged_list.head = merged_head
    merged_list.display()