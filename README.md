ReadME:
The Following Project implements graphing Algorithms learned in last semester in CPP;
the project uses different data structures : Stack,Queue,Priority Queue,UnionFind and adjacency list to represnt an undirected graph.
The data structures are used to manage the graph traversal and operations efficiently.
The following ReadMe file provides a general and a detailed explanation of each class and its functions.

Struct Node:
 This is a helper structure that represents an individual edge in the graph. Each node in the adjacency list corresponds to a vertex connected to another vertex.
Variables:
int vertex: This stores the destination vertex of the edge.
int weight: This stores the weight of the edge.
Node* next: This is a pointer to the next node in the adjacency list. It's used to form a linked list structure for each vertex’s adjacency list.
Constructor (Node(int v, int w)): Initializes a node with the given vertex v and weight w. The next pointer is set to nullptr initially.

Class Graph:


Node** adjList:
 This is a dynamic array of pointers, where each element in the array represents the adjacency list for a specific vertex. Each vertex will have its own linked list of edges (using Node objects).
 It’s a pointer to a pointer, where the first pointer points to the array and the second pointer represents the head of a linked list of connected nodes for each vertex.
int numVertices:
This stores the number of vertices in the graph. It is set during the creation of the graph and is used to determine the size of the adjacency list and ensure valid operations within bounds.

Graph(int vertices):
This constructor initializes the graph with a given number of vertices.
Variables:
numVertices: Sets the number of vertices in the graph.
adjList: Dynamically allocates memory for an array of Node* pointers. Each entry in this array represents a vertex and is initially set to nullptr, meaning each vertex has no edges initially.

int getNumVertices():
Purpose: Returns the number of vertices in the graph. This is useful when you want to know how many vertices are in the graph for traversal or processing.

Node* getAdjList(int v):
 Returns the adjacency list of the vertex v.
 The adjacency list is a linked list of Node objects, each of which represents an edge. This function is useful to retrieve all the neighbors of a given vertex v.

 ~Graph()
 The destructor is responsible for deallocating the dynamically allocated memory used by the graph. It ensures that all the memory used by the adjacency list is properly freed.
For each vertex, the adjacency list (a linked list) is traversed, and each node is deleted.
After all edges for all vertices are deleted, the adjList array itself is deallocated using delete[].

void addEdge(int src, int dst, int weight):
This function adds an undirected edge between two vertices src and dst with a given weight. Since it is an undirected graph, an edge is added in both directions.
Vertex Index Validation: First, it checks if the vertex indices src and dst are valid. If they are out of bounds, it throws a runtime error.
For the edge from src to dst, a new Node is created with dst as the vertex and the specified weight.
This node is then added at the beginning of the adjacency list of src.
Similarly, an edge from dst to src is added.

void removeEdge(int src, int dst):
 Removes an edge between two vertices src and dst (undirected). It handles removing the edge from both vertices' adjacency lists.
Edge Existence Check: If either of the vertices has no edges , it throws an error.
Edge Removal:
For both vertices (src and dst), the function traverses the adjacency list to find the edge.
Once found, the corresponding node is removed from the list and deleted.



Queue class:
The destructor ensures that all dynamically allocated memory for the nodes is properly freed when the queue object is destroyed.
It uses a while loop to traverse the queue and delete each node one by one.
The temp pointer temporarily stores the current head.
The head is then updated to the next node in the list (head->next), and the node is deleted.

enqueue():
This function adds a new node to the back of the queue.
It takes two parameters, vertex and weight, which are passed to the Node constructor to create a new node.
vertex: Represents a data element (often the node's ID or identifier).
weight: Represents some associated weight or value (this could represent priority or distance, depending on the context).
If the queue is empty (head == nullptr), both head and tail are set to point to the new node.
If the queue is not empty, the next pointer of the current tail node is updated to point to the new node, and then the tail is updated to the new node.
Finally, the size of the queue is incremented by 1.

deQueue():
Purpose: This function removes and returns the data from the front of the queue.
If the queue is empty (size == 0), it returns -1 to indicate the queue is empty.
The front node (head) is removed by updating head to point to the next node in the list.
If the queue has only one element (i.e., head == tail), both head and tail are set to nullptr.
The vertex value of the removed node is stored in value.
The node is then deleted, and the queue size is decreased by 1.
Finally, the vertex value is returned, representing the element that was removed from the front of the queue.

isempty():
Just checks if the Queue is empty or not.

Stack:
Destrucor:
does the same as the Queue;

pop():
Purpose: This function removes and returns the data from the top of the stack.
If the stack is empty (head == nullptr), it returns -1 to indicate the stack is empty.
The head pointer is updated to point to the next node (head->next), effectively removing the top node from the stack.
The vertex value of the removed node is stored in the value variable.
The node is then deleted, and the size of the stack is decremented by 1.
Finally, the vertex value is returned, representing the element that was removed from the top of the stack.

push():
Purpose: This function adds a new node to the top of the stack.
It takes two parameters: vertex (the data value) and weight (an associated value, which could represent priority or another piece of data).
A new node is created with the vertex and weight values.
The next pointer of the new node is set to the current head of the stack, linking the new node to the existing stack.
The head pointer is updated to point to the new node, making it the top of the stack.
The size of the stack is incremented by 1.

isEmpty():
same as before.

Edge:
SetEdge():
Purpose: This function sets the source vertex (srcedge), destination vertex (dstedge), and the weight (weight) of the edge.
The this pointer refers to the current instance of the class. This is used to differentiate the class's member variables from the function's parameters.
It allows you to modify the properties of the edge after the object has been created.

getDstedge():
This function returns the destination vertex

SetEdge():
 Sets or updates the source vertex

int size:
This variable represents the total capacity of the heap, or the maximum number of elements the heap can hold.
int *heapValues:
This is an array that stores the values of the elements in the heap (typically representing the key or weight of the heap element).
int *heapIndexes:
This array stores the index associated with each element in the heap. It allows us to track which vertices or nodes each value is related to.
int *heapPrev:
This array stores a "previous" value for each element, which could represent the source vertex or some other associated information with the heap element. In the context of a graph, it could store information about the previous vertex or edge.
int numOfElements:This variable tracks the current number of elements in the heap. It is initialized to 0 when the heap is empty.

heapifyUP(int index):
Purpose: The heapifyUP function ensures that the heap property is maintained when a new element is added. Specifically, if a newly added element is smaller than its parent, this function will swap them, moving the element upwards until the heap property is satisfied.
How it works:
It compares the value at the given index with its parent's value. If the child's value is smaller, it swaps the values of the child and the parent.
It continues recursively with the parent's index until the heap property is satisfied or the root is reached.

heapifyDown(int index):
Purpose: The heapifyDown function maintains the heap property after removing an element (such as when popping from the heap).
How it works:
It compares the value at the given index with its children (left and right). If either child is smaller than the current element, it swaps the current element with the smallest child.
This process is repeated recursively until the heap property is restored.

push(int value, int index, int prev):
Purpose: The push function adds a new element to the heap, placing it in the appropriate position to maintain the heap property.
How it works:
If the heap is empty, it directly places the value, index, and previous value in the first position.
Otherwise, it adds the element at the next available position, then calls heapifyUP to ensure the heap property is maintained by comparing the element with its parent.
The numOfElements counter is incremented.

pop()
Purpose: The pop function removes and returns the smallest element (root of the heap), then restores the heap property by calling heapifyDown.
How it works:
The root element (smallest) is stored, then replaced with the last element in the heap.
numOfElements is decremented, and heapifyDown is called to restore the heap property starting from the root.
The function returns an Edge object created using the data from the popped element (the root value, index, and previous value).


UnionFind:

int value:
This variable stores the value associated with the current UnionFind object.
It can represent a unique identifier for each element in the union-find data structure.
UnionFind* pointsTo:
This is a pointer to another UnionFind object, which represents the parent or "leader" of the current set (also known as the representative or root).
Initially, each element points to itself, indicating it is its own root.

find():
Purpose: The find function returns the representative (or root) of the set to which the current UnionFind object belongs. It also performs path compression to flatten the tree structure, making future find operations faster.
How it works:
If the current object is not the root (i.e., this->value != this->pointsTo->value), the function recursively calls find() on the parent (this->pointsTo) to get the root of the set.
After finding the root, it applies path compression by making each element along the path point directly to the root, thus flattening the tree structure for faster future lookups.
The function returns the root (the representative element) of the set.

union_sets(UnionFind* u):
Purpose: The union_sets function merges the sets of two elements, this and u, by linking their roots.
How it works:
First, it finds the roots (representatives) of both this and u by calling find() on both.
If the roots are different, it means the two sets are disjoint. In this case, it connects root_u to root_v, effectively merging the sets. This is done by setting root_u->pointsTo = root_v, making root_v the new leader of the merged set.


Algorithm Class:
BFS:
graph: A pointer to the graph object that represents the graph in which BFS is to be performed.
src: The source vertex from which BFS starts.
Returns: A new graph (bfstree) that represents the BFS tree (or forest). This graph will contain the edges that represent the connections made during the BFS traversal.
Algorithm Steps:
Get the number of vertices in the graph using graph->getNumVertices().
Create a visited array to keep track of which vertices have been visited.
Create a new bfstree graph to store the BFS tree.
Initialize a queue to explore vertices in the correct order.
Start BFS:
Mark the src vertex as visited and enqueue it into the queue.
While the queue is not empty:
Dequeue the current node and retrieve its adjacency list (neighbors).
For each neighbor, if it hasn't been visited, mark it as visited and enqueue it.
Add an edge between the current node and its neighbor in the bfstree.
Return the BFS Tree: Once BFS is complete, return the bfstree.

DFS:
Get the number of vertices in the graph.
Create a visited array to keep track of which vertices have been visited.
Create a new DFSTree graph to store the DFS tree.
Initialize a stack to perform DFS.
Start DFS:
Mark the src vertex as visited and push it onto the stack.
While the stack is not empty:
Pop the current node from the stack and retrieve its adjacency list.
For each neighbor, if it hasn't been visited, mark it as visited and push it onto the stack.
Add an edge between the current node and its neighbor in the DFSTree.
Return the DFS Tree: Once DFS is complete, return the DFSTree.

prim:
visited: A boolean array to track which vertices have been added to the MST.
mst: A new graph object to store the minimum spanning tree.
heap: A min-heap (priority queue) to store the edges of the graph, sorted by edge weight. The heap ensures that we always pick the minimum weight edge.
Start with Vertex 0:
Mark vertex 0 as visited (visited[0] = true).
Push all adjacent edges of vertex 0 into the heap.
Process the Heap:
While the heap is not empty, pop the smallest edge (curr).
If the destination vertex of the edge has not been visited, add it to the MST and mark it as visited.
Add all the neighbors of the newly added vertex to the heap if they have not been visited.
Return the MST: Once the heap is empty, the MST is fully constructed, and the function returns the mst graph.

Dijkstra:
visited: A boolean array to track which vertices have been processed.
shortestDist: An array to store the shortest distance from the source to each vertex.
resultGraph: A new graph object to store the edges of the shortest paths.
heap: A min-heap to select the vertex with the smallest tentative distance efficiently.
Initialization:
Set all distances to INT_MAX (infinity) except for the source vertex, which is set to 0.
Push all neighbors of the source vertex into the heap.
Process the Heap:
While the heap is not empty, pop the edge with the smallest tentative distance.
If the destination vertex has already been visited, skip it.
Otherwise, mark the vertex as visited and add the edge to the resultGraph.
Update the distances of the neighbors of the current vertex. If a shorter distance is found, update the distance and push the neighbor into the heap.
Return the Result: Once all vertices have been processed, return the resultGraph containing the shortest paths.

Kruskals:
numVertices: The number of vertices in the graph.
mst: A new graph object to store the MST.
edgeCount: A counter to track the number of edges added to the list.
uf: An array of UnionFind objects used to keep track of connected components (disjoint-set).
edges: An array to store all edges of the graph.
Fill Edge List:
Loop through each vertex in the graph.
For each vertex, loop through its adjacency list to collect all the edges. Only edges where i < adjList->vertex are added to avoid duplicates (since the graph is undirected).
Sort Edges by Weight:
Sort the edges in non-decreasing order of their weights using bubble sort (not optimal, but simple for this purpose).
Union-Find Initialization:
Initialize each vertex's UnionFind object. Set the pointsTo pointer to itself, indicating that each vertex initially represents its own set.
Build the MST:
Loop through each sorted edge and check if the vertices of the edge belong to the same set using the find operation.
If they are in different sets, add the edge to the MST and unite the sets using the union_sets operation. This ensures no cycles are formed.
Return the MST: Once all edges are processed, return the mst graph containing the minimum spanning tree.

Bibliography:
https://www.youtube.com/@coding_with_rai/videos.
Moodle of courses from last Semester.
https://www.geeksforgeeks.org/kruskals-minimum-spanning-tree-algorithm-greedy-algo-2/--(also for the other algorithms).






 
