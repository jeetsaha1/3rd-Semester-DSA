#  Write a program to implement Binary Search Tree using linked list along with the following functions: 
# To create a binary search tree.
#  To display tree using infix.
# To display tree using prefix.
# To display tree using postfix.
# To count number of node present in the tree.
# To find the height of the tree. 
# To find the number of leaf node.
# To find the number of internal node.
# To search a data present in the tree.
# To check complete binary tree.
# To insert a node.
# To delete a node.
# To check the balance factor of a node.
# To find the minimum value present in the tree.
# To find the maximum value present in the tree.
# To count number of NULL pointer present in the tree.


class node:
    def __init__(self,data):
        self.data = data
        self.left = None
        self.right = None

class BST:
    def __init__(self):
        self.root = None
    
    def createBST(self,data):
        if self.root is None:
            newNode = node(data)
            self.root = newNode
        elif self.root.data > data:
            self.root.left = self.createBST(self.root.left, data)
        elif self.root.data < data:
            self.root.right = self.createBST(self.root.right, data)
        return self.root
    
    def inorder(self):
        if self.root is not None:
            self.inorder(self.root.left)
            print(self.root.data,end=" ")
            self.inorder(self.root.right)

if __name__ == "__main__":
    bst = BST()
    ch = -1
    while ch != 0:
        data = int(input("Enter the data: "))
        bst.createBST(data)
        ch = int(input("Do you want to insert:"))
    print("Inorder: ")
    bst.inorder()