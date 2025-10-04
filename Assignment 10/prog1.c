// Write a C program to implement Graph using Adjacency Matrix along
// with the following function:
// a) To count number of vertices and edges present in a graph.
// b) To find the adjacent vertices of a given vertex.
// c) To search a node in a given graph.

#include<stdio.h>
#include<stdlib.h>

//Definig the static value
#define MAX 100

// Function for printing the number of vertex
int count_vertices(int vertices){
    return vertices;
}

// Function for counting the edges(Asssuming that the graph is undirectional)
int count_edges(int adj[MAX][MAX], int vertices){
    int count = 0;
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++){
            if (adj[i][j] == 1)
                count ++;
        }
    }
    return count/2;   
}

// Finding the adjacent vertices of the vertex
void adjacent_vertices(int adj[MAX][MAX], int vertex, int vertices){
    printf("Adjacent vertices of %d: ", vertex);
    for (int i = 0; i < vertices; i++)
    {
        if(adj[vertex][i] == 1)
            printf("%d ",i);
    }
}

// For Searching whether the searched node exists or not
void searchNode(int x, int vertices){
    if (x < 0 || x >= vertices) 
        printf("Node %d does not exist in the graph.\n", x);
    else 
        printf("Node %d exists in the graph.\n", x);
}

int main(){
    //Initialize
    int vertices, edges, vertex;
    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);

    int adj[MAX][MAX];

    for (int i = 0; i < vertices; i++)
        for (int  j = 0; j < vertices; j++)
            adj[i][j] = 0;
    
    printf("Enter the number of edges: ");
    scanf("%d",&edges);
    
    //Entering the nodes
    for (int i = 0; i < edges; i++)
    {
        int x,y;
        printf("Enter x: ");
        scanf("%d",&x);
        printf("Enter y: ");
        scanf("%d",&y);

        adj[x][y] = adj[y][x] = 1;
    }

    //Printing the adjacent matrix
    for (int i = 0; i < vertices; i++)
    {
        for (int j = 0; j < vertices; j++)
        {
            printf("%d ",adj[i][j]);
        }
        printf("\n");
    }

    //Printing the vertices and edges
    printf("The number of vertices is: %d",count_vertices(vertices));
    printf("The number of edges is: %d",count_edges(adj,vertices));

    // Printing Adjacent vertices
    printf("Enter the vertex: ");
    scanf("%d",&vertex);
   if(vertex >= 0 && vertex < vertices) {
    adjacent_vertices(adj, vertex, vertices);
    } else {
        printf("Invalid vertex! Please enter a number between 0 and %d\n", vertices-1);
    }

    //Searching the nodes
    int node;
    printf("\nEnter the node to search: ");
    scanf("%d", &node);
    searchNode(node, vertices);
    return 0;
}