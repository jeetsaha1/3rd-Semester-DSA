# Write a C program to implement Graph using Adjacency list along with
# the following function:
# a) To count number of vertices and edges present in a graph.
# b) To find the adjacent vertices of a given vertex.
# c) To search a node in a given graph.

def count_vertices(vertices):
    return vertices

def count_edges(adj, vertices):
    count = 0
    for i in range(0,vertices):
        for j in range(0,vertices):
            if adj[i][j] ==1:
                count+= 1
    return count/2

def adjacency_vertices(adj, vertex, vertices):
    print(f"Adjacent vertices of{vertex}: ")
    for i in range(0, vertices):
        if adj[vertex][i] == 1:
            print(i)

def searchNode(x, vertices):
    if x< 0 or x>vertices:
        print(f"Node{x} deoes not exist in the graph\n")
    else:
        print(f"Node {x} exists in the graph.\n", x)


vertices = int(input("Enter the number of vertices: "))
adj = [[0 for _ in range(vertices)]for _ in range(vertices)]
edges = int(input("Enter the numver of Edges: "))

for k in range(0,edges):
    x = int(input("Enter x: "))
    y = int(input("Enter y: "))
    adj[x][y], adj[y][x] = 1,1

for i in range(0,vertices):
    for j in range(0,vertices):
        print(adj[i][j], end=" ")
    print("\n")


print("The number of the vertices is:",count_vertices(vertices))
print("The number of the edges is:",count_edges(adj,vertices))

vertex = int(input("Enter the vertex: "))
if(vertex>=0 and vertex < vertices):
    adjacency_vertices(adj, vertex, vertices)
else:
    print("Invalid Index")

node = int(input("Enter the node to search: "))
searchNode(node, vertices)