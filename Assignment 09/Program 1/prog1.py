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
        def _createBST(root,data):
            if root is None:
                return node(data)
            elif root.data > data:
                root.left = _createBST(root.left, data)
            elif root.data < data:
                root.right = _createBST(root.right, data)
            return root
        self.root = _createBST(self.root,data)
    
    def inorder(self):
        def _inorder(root):
            if root is not None:
                _inorder(root.left)
                print(root.data,end=" ")
                _inorder(root.right)
        _inorder(self.root)

    def preorder(self):
        def _preorder(root):
            if root is not None:
                print(root.data,end=" ")
                _preorder(root.left)
                _preorder(root.right)
        _preorder(self.root)

    def postorder(self):
        def _postorder(root):
            if root is not None:
                _postorder(root.left)
                _postorder(root.right)
                print(root.data, end=" ")
        _postorder(self.root)

    def count_node(self):
        def _count_node(root):
            if root is None:
                return 0
            else:
                return 1 + _count_node(root.left)+ _count_node(root.right)
        return _count_node(self.root)
    
    def height(self):
        def _height(root):
            if root is None:
                return 0
            else:
                left = _height(root.left)
                right = _height(root.right)
                return 1 + max(left,right)
        return _height(self.root)
    
    def count_leaf_node(self):
        def _count_leaf_node(root):
            if root == None:
                return 0
            elif root.left == None and root.right == None:
                return 1
            else:
                return _count_leaf_node(root.left)+ _count_leaf_node(root.right)
        return _count_leaf_node(self.root)
    
    def count_internal_node(self):
        def _count_internal_node(root):
            if root == None:
                return 0
            elif root.left == None and root.right == None:
                return 0
            else:
                return 1 +  _count_internal_node(root.left)+ _count_internal_node(root.right)
        return _count_internal_node(self.root)
    
    def searchBSt(self,data):
        def _searchBSt(root,data):
            if root is None:
                return 0
            if root.data == data:
                return 1
            elif (root.data >= data):
                return _searchBSt(root.left, data)
            else:
                return _searchBSt(root.right,data)
        return _searchBSt(self.root,data)
    
    
    def is_completeUtil(self, root, index, total_nodes):
        if root is None:
            return True
        if index >= total_nodes:
            return False
        return (self.is_completeUtil(root.left, 2*index + 1, total_nodes) and
                self.is_completeUtil(root.right, 2*index + 2, total_nodes))
    
    def is_complete(self):
        totalNodes = self.count_node()
        return self.is_completeUtil(self.root,0,totalNodes)
    
    def insert(self, data):
        def _insert(root, data):
            if root is None:
                return node(data)
            if data < root.data:
                root.left = _insert(root.left, data)
            elif data > root.data:
                root.right = _insert(root.right, data)
            return root
        self.root = _insert(self.root, data)


    def max_value(self):
        if self.root is None:
            return None
        current = self.root
        while current.right is not None:
            current = current.right
        return current.data

    def min_value(self):
        if self.root is None:
            return None
        current = self.root
        while current.left is not None:
            current = current.left
        return current.data  
        
    def count_NULL_pointer(self):
        def _count_NULL_pointer(root):
            if root == None:
                return 1
            return _count_NULL_pointer(root.left)+ _count_NULL_pointer(root.right)
        return _count_NULL_pointer(self.root)
    

if __name__ == "__main__":
    bst = BST()

    ch = -1
    while ch != 0:
        data = int(input("Enter the data: "))
        bst.createBST(data)
        ch = int(input("Do you want to insert:"))

    print("Inorder: ")
    bst.inorder()

    print("\nPreorder: ")
    bst.preorder()

    print("\nPostorder: ")
    bst.postorder()

    print("\n",bst.count_node())

    print("\n",bst.height())

    print("\n",bst.count_leaf_node())

    print("\n",bst.count_internal_node())

    ele = int(input("Enter the element for searching: "))
    if bst.searchBSt(ele):
        print("The element is found")
    else:
        print("The element is not found")

    # if bst.complete_bin_tree():
    #     print("This is a complete binary tree")
    # else:
    #     print("This is not a complete binary tree")

    data = int(input("Enter the element to insert: "))
    bst.insert(data)
    bst.inorder()

    print(bst.max_value())

    print(bst.min_value()) 


    # suppose bst.root is already built
# total_nodes = bst.count_nodes(bst.root)

if bst.is_complete():
    print("Tree is Complete")
else:
    print("Tree is NOT Complete")
