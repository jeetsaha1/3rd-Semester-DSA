//  Write a program to implement Binary Search Tree using linked list along with the following functions: 
// To create a binary search tree.
//  To display tree using infix.
// To display tree using prefix.
// To display tree using postfix.
// To count number of node present in the tree.
// To find the height of the tree. 
// To find the number of leaf node.
// To find the number of internal node.
// To search a data present in the tree.
// To check complete binary tree.
// To insert a node.
// To delete a node.
// To check the balance factor of a node.
// To find the minimum value present in the tree.
// To find the maximum value present in the tree.
// To count number of NULL pointer present in the tree.



#include<stdio.h>
#include<stdlib.h>

//Making the structure 
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}node;

node *createBST(node *root, int data){
    if (root == NULL){
        node *nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->left = nw->right =NULL;
        root = nw;
    }
    else if(root->data > data){
        root->left = createBST(root->left, data);
    }
    else if(root->data < data){
        root->right = createBST(root->right, data);
    }
    return root;
}

void inorder(node *root){
    if (root!= NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void preorder(node *root){
    if (root!= NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(node *root){
    if (root!= NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

int count_nodes(node *root){
    if (root == NULL)
        return 0;
    else{
        return 1+count_nodes(root->left)+ count_nodes(root->right);
    }
}

int max(int a, int b){
    return a>b?a:b;
}

int height(node *root){
    if (root == NULL)
        return 0;
    else{
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(rightHeight,leftHeight);
    }
}

int count_leaf_node(node *root){
    if (root == NULL)
        return 0;
    if (root->left == NULL || root->right == NULL)
        return 1;
    return count_leaf_node(root->left) + count_leaf_node(root->right);   
}

int count_internal_node(node *root){
    if (root == NULL)
        return 0;
    if (root->left == NULL || root->right == NULL)
        return 0;
    return 1+count_internal_node(root->left)+count_internal_node(root->right);
}

int searchBST(node *root, int val){
    if (root == NULL)
        return 0;
    if (root->data == val)
        return 1;
    else if (root->data > val)
        return searchBST(root->left,val);
    else
        return searchBST(root->right,val);
}

// int isBST(struct Node * root){
//     static struct Node * prev =NULL;
//     if (root!=NULL)
//     {
//         if (!isBST(root->left))
//         {
//             return 0;
//         }
//         if (prev != NULL && root->data <= prev->data)
//             return 0;
//         prev = root;
//         return isBST(root->right);
//     }
//     else
//         return 1;
// }

int iscompleteUtil(node *root, int index, int totalNodes){
    if(root == NULL)
        return 1;
    if (index > totalNodes)
        return 0;
    return (iscompleteUtil(root->left,2*index+1, totalNodes) && iscompleteUtil(root->right, 2*index+2,totalNodes));
}

int isComplete(node *root){
    int totalNodes = count_nodes(root);
    return iscompleteUtil(root, 0, totalNodes);
}

int min_value(node *root){
    while (root->left != NULL)
    {
        root = root->left;
    }
    return root->data;
}

int max_value(node *root){
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root->data;
}

int counting_NULL_pointer(node *root){
    if (root == NULL)
        return 1;
    return counting_NULL_pointer(root->left)+counting_NULL_pointer(root->right);
}

int balance_factor(node *root, int ele) {
    if (root == NULL)
        return -9999;  // element not found flag

    if (ele < root->data)
        return balance_factor(root->left, ele);
    else if (ele > root->data)
        return balance_factor(root->right, ele);
    else { 
        int left_height = height(root->left);
        int right_height = height(root->right);
        return left_height - right_height;
    }
}

void insert(node * root,int key){
    node * prev = NULL;
    while(root!=NULL){
        prev = root;
        if(key == root->data)
            return;
        else if(key < root->data)
            root = root->left;
        else   
            root = root->right;
    }

    node *nw = (node*)malloc(sizeof(node));
    nw->data = key;
    nw->left = nw->right = NULL;
    if(key < prev->data)
        prev->left = nw;
    else
        prev->right = nw;
}

node * inorderpredecessor(node * root){   
    root = root->left;      //In order predeccessor is the most right node of the left subtree
    while(root->right!=NULL){
        root= root->right;
    }
    return root;
}

node * deleteNode(node * root, int value){
    struct Node *iPre;   // For taking the in Order Predecessor
    if(root==NULL){
        return NULL;
    }
    if(root->left ==  NULL && root->right == NULL){
        free(root);
        return NULL;
    }

    if (value< root->data)
        root->left= deleteNode(root->left , value);
    else if(value> root->data)
        root->right = deleteNode (root->right,value);
    else{
        iPre = inorderpredecessor(root);
        root->data = iPre ->data;
        root->left = deleteNode(root->left,iPre->data);
    }
    return root;
}

int main(){
    node *root = NULL;
    //1
    int data, ch= -1;
    while(ch != 0){
        printf("Enter the number: ");
        scanf("%d",&data);

        root = createBST(root, data);

        printf("Do you want to insert(1/0):");
        scanf("%d",&ch);
    }
    //2
    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    //3
    preorder(root);
    printf("\nPostorder: ");
    //4
    postorder(root);
    printf("\n");
    //5
    printf("Number of nodes:%d\n",count_nodes(root));
    //6
    printf("Height of the tree:%d\n",height(root));
    //7
    printf("Number of leaf nodes:%d\n",count_leaf_node(root));
    //8
    printf("Number of internal nodes:%d\n",count_internal_node(root));
    //9
    int ele;
    printf("Enter the data for seaching: ");
    scanf("%d",&ele);
    if(searchBST(root,ele))
        printf("The element is found\n");
    else
        printf("The element is not found\n");
    //10
    if(isComplete(root))
        printf("This is complete Binary Tree\n");
    else
        printf("This is not a complete Binary Tree\n");
    //11
    printf("Enter the element for inserting: ");
    scanf("%d",&ele);
    insert(root,ele);
    printf("The data is inserted..\n");
    //12
    printf("Enter the element for deleting: ");
    scanf("%d",&ele);
    root = deleteNode(root,ele);
    inorder(root);
    //13
    printf("Enter the element for checking Balance factor: ");
    scanf("%d",&ele);
    printf("%d",balance_factor(root,ele));
    //14
    printf("Max node: %d\n",max_value(root));
    //15
    printf("Min node: %d\n",min_value(root));
    //16
    printf("The no. of NULL pointers: %d\n",counting_NULL_pointer(root));
    
    return 0;
}


// Enter the number: 10
// Do you want to insert(1/0):1
// Enter the number: 5
// Do you want to insert(1/0):1
// Enter the number: 15
// Do you want to insert(1/0):0
// Inorder: 5 10 15 
// Preorder: 10 5 15
// Postorder: 5 15 10
// Number of nodes:3
// Height of the tree:2
// Number of leaf nodes:2
// Number of internal nodes:1
// Enter the data for seaching: 10
// The element is found
// This is complete Binary Tree
// Enter the element for inserting: 5
// The data is inserted..
// Enter the element for deleting: 5
// 10 15 Enter the element for checking Balance factor: 15
// 0Max node: 15
// Min node: 10
// The no. of NULL pointers: 1