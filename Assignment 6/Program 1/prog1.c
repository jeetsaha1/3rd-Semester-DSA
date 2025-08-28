// 1. Write a program to implement Binary Tree using array along with the     
//      following functions: 
// a.To create a binary tree.
// b.To display tree using inorder.
// c.To display tree using preorder.
// d.To display tree using postorder.
// e.To count number of node present in the tree.
// f.To find the height of the tree. 
// g.To find the number of leaf node.
// h.To find the number of internal node.
// i.To search a data present in the tree.


#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define MAX 100

int max(int a,int b){
    int m = a>b? a:b;
    return m;
}

//a. To create Binary Tree
void create_binary_tree(int tree[]){
    int h;                          //At first enter the height
    printf("Enter the height of the tree: ");
    scanf("%d",&h);

    int n = (int)pow(2,h)-1;        //Maximum no. of nodes

    for (int i = 0; i < MAX; i++)   // Initialize with -1
        tree[i] = -1;

    printf("Enter the root of the tree: ");     //Entering the root of the tree
    scanf("%d",&tree[0]);

    //Adding another nodes
    for (int i = 0; i < n; i++)
    {
        if(tree[i] != -1){
            printf("Enter the left child of %d: ",tree[i]);
            scanf("%d",&tree[2*i+1]);

            printf("Enter the right child of %d: ",tree[i]);
            scanf("%d",&tree[2*i+2]);
        }
    }
}

//b. Display inorder
void inorder(int tree[], int i){
    if (tree[i] != -1){
		inorder(tree,2*i+1);
		printf("%d ",tree[i]);
		inorder(tree, 2*i+2);
	}
}

//c. Display preorder
void preorder(int tree[], int i){
    if (tree[i] != -1){
        printf("%d ",tree[i]);
        preorder(tree,2*i+1);
        preorder(tree,2*i+2);
    }
}

//d. Display postorder
void postorder(int tree[], int i){
    if (tree[i] != -1){
        postorder(tree,2*i+1);
        postorder(tree,2*i+2);
        printf("%d ",tree[i]);
    }
}

//e. Count nodes
int count_nodes(int tree[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] != -1){
            count++;
        }
    }
    return count;
}

//f. Height of a tree
int height (int tree[], int i){
    if (tree[i] == -1)
        return 0;
    else{
        int lefthight = height(tree, 2*i+1);
        int rightheight = height(tree, 2*i+2);
        return 1+ max(lefthight,rightheight);
    }
}

//g.Number of leaf nodes
int count_leaf_nodes(int tree[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] != -1 && tree[2*i+1] == -1 && tree[2*i+2] == -1)
            count++;
    }
    return count;
}

//h.Number of internal node
int count_internal(int tree[], int n){
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (tree[i] != -1 && tree[2*i+1] != -1 || tree[2*i+2] != -1)
            count++;
    }
    return count;
}

//i.searching an element
int searching_element(int tree[],int n,int ele){
    for (int i = 0; i < n; i++)
    {
        if (tree[i] == ele)
            return i;
    }
    return -1;
}

int main(){
    int tree[MAX];
    create_binary_tree(tree);
    inorder(tree,0);
    printf("\n");
    preorder(tree,0);
    printf("\n");
    postorder(tree,0);
    printf("\n");
    printf("The number of nodes: %d",count_nodes(tree,(int)pow(2,3)-1));
    printf("\n");
    printf("The height of the tree: %d",height(tree,0));
    printf("\n");
    printf("The number of the leaf nodes: %d",count_leaf_nodes(tree,(int)pow(2,3)-1));
    printf("\n");
    printf("The number of interal node is: %d",count_internal(tree,(int)pow(2,3)-1));
    printf("\n");
    int ele;
    printf("Enter the number for seraching: ");
    scanf("%d",&ele);
    int res = searching_element(tree,(int)pow(2,3)-1,ele);
    if (res != -1)
        printf("The element is found at %d no. node",res);
    else
        printf("Not found");
    return 0;
}