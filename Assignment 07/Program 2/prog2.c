// Write a program to implement Binary Tree using linked list along with the     
//      following functions: 
// To create a binary tree.
//  To display tree using inorder.
// To display tree using preorder.
// To display tree using postorder.
// To count number of node present in the tree.
// To find the height of the tree.
// To find the number of leaf node.
// To find the number of internal node.
// To search a data present in the tree.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//At first making a structure for making a node
typedef struct Node{
    int data;
    struct Node *left;
    struct Node *right;
}node;

//a. Creating a binary tree
node *createBinaryTree(){
    node *nw , *root = NULL;
    int data, ch = -1;

    while(ch != 0){
        printf("Enter the data: ");
        scanf("%d",&data);

        nw = (node*)malloc(sizeof(node));
        nw->data = data;
        nw->left = nw->right = NULL;

        if (root == NULL)
            root = nw;
        else{
            node *p = root;
            while(1){
                char side[10];
                printf("In which side you want to insert: ");
                scanf("%s",side);

                if (strcmp(side,"left") == 0){
                    if (p->left == NULL){
                        p->left = nw;
                        break;
                    }
                    else
                        p = p->left;
                }
                else if (strcmp(side,"right")== 0)
                {
                    if (p->right == NULL){
                        p->right = nw;
                        break;
                    }
                    else
                        p = p->right;
                }
            }
            
        }
        printf("Do you want to insert (1/0): ");
        scanf("%d",&ch);
    }
    return root;
}

//b. Inorder
void inorder(node *root){
    if (root != NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

//c.Preorder
void preorder(node *root){
    if (root != NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//d. Postorder
void postorder(node *root){
    if (root != NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

//e. Counting nodes
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

//f.height of the tree
int height(node *root){
    if (root == NULL)
        return 0;
    else{
        int leftHeight = height(root->left);
        int rightHeight = height(root->right);
        return 1 + max(rightHeight,leftHeight);
    }
}

//g.Number of leaf node
int count_leaf_node(node *root){
    if (root == NULL)
        return 0;
    if (root != NULL && (root->left == NULL || root->right == NULL))
        return 1;
    return count_leaf_node(root->left) + count_leaf_node(root->right);   
}

//h. Counting the internal node
int count_internal_node(node *root){
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 0;
    return 1 + count_internal_node(root->left) + count_internal_node(root->right);   
}

//i. Searching an element
int searching_element(node *root, int ele){
    if (root == NULL)
        return 0;
    if (root->data == ele)
        return 1;
    else{
        return searching_element(root->left,ele);
    }
    return searching_element(root->right,ele);
    
}
int main(){
    node *root;
    root = createBinaryTree();
    inorder(root);
    printf("\n");
    preorder(root);
    printf("\n");
    postorder(root);
    printf("\n");

    printf("The number of nodes: %d",count_nodes(root));
    printf("\n");
    printf("The height of the tree: %d",height(root));
    printf("\n");
    printf("The number of the leaf nodes: %d",count_leaf_node(root));
    printf("\n");
    printf("The number of interal node is: %d",count_internal_node(root));
    printf("\n");
    int ele;
    printf("Enter the number for seraching: ");
    scanf("%d",&ele);
    int res = searching_element(root,ele);
    if (res != 0)
        printf("The element is found");
    else
        printf("Not found");
    return 0;
}

// Enter the data: 10
// Do you want to insert (1/0): 1
// Enter the data: 4
// In which side you want to insert: left
// Do you want to insert (1/0): 1
// Enter the data: 6
// In which side you want to insert: right
// Do you want to insert (1/0): 0
// 4 10 6 
// 10 4 6
// 4 6 10
// The number of nodes: 3
// The height of the tree: 2
// The number of the leaf nodes: 2
// The number of interal node is: 1
// Enter the number for seraching: 10
// The element is found