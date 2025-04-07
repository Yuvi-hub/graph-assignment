#include <iostream>
#include "Graph.h"
#include <stdexcept>
#include <limits.h>
#include "Algorithm.h"
using namespace std;
using namespace graph;

namespace graph {

    Queue::Queue() : head(nullptr), tail(nullptr), size(0) {}

    Queue::~Queue() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp; 
        }
    }

    void Queue::enqueue(int vertex, int weight) {
        Node* node = new Node(vertex, weight);
        if (head == nullptr) {
            head = node;
            tail = node;
        } else {
            tail->next = node;
            tail = node;
        }
        size++;
    }

    int Queue::deQueue() {
        if (size == 0) {
            return -1;
        }

        Node* temp = head;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
        }
        int value = temp->vertex;
        size--;
        delete temp;
        return value;
    }

    bool Queue::isempty() {
        return size == 0;
    }

    Stack::Stack() : head(nullptr), size(0) {}

    Stack::~Stack() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;  
        }
    }

    int Stack::pop() {
        if (head == nullptr) {
            return -1;
        }

        Node* temp = head;
        head = head->next;
        int value = temp->vertex;
        size--;
        delete temp;
        return value;
    }

    void Stack::push(int vertex, int weight) {
        Node* node = new Node(vertex, weight);
        node->next = head;
        head = node;
        size++;
    }

    bool Stack::isEmpty() {
        return size == 0;
    }

    Edge::Edge(int srcedge, int dstedge, int weight) : srcedge(srcedge), dstedge(dstedge), weight(weight) {}

    Edge::Edge() : srcedge(0), dstedge(0), weight(0) {}

    void Edge::SetEdge(int srcedge, int dstedge, int weight) {
        this->srcedge = srcedge;
        this->dstedge = dstedge;
        this->weight = weight;
    }

    int Edge::getDstedge() {
        return dstedge;
    }

    Heap::Heap(int size) : size(size), heapValues(new int[size]), heapIndexes(new int[size]), heapPrev(new int[size]), numOfElements(0) {}

    Heap::~Heap() {
        delete[] heapValues;
        delete[] heapIndexes;
        delete[] heapPrev;
    }

    void Heap::heapifyUP(int index){

        int fatherIndex;
            int indexHeap = index+1;
            int fatherIndexHeap;
            if(index == 0) {
                return;
            }
            if (indexHeap % 2==1) {
                fatherIndexHeap = (indexHeap-1)/2;
            }
            else {
                fatherIndexHeap = indexHeap/2;
            }

            fatherIndex = fatherIndexHeap -1;

            int temp;

                
            if (this->heapValues[index]<this->heapValues[fatherIndex])
            {      
                temp = this->heapValues[index];
                this->heapValues[index] = this->heapValues[fatherIndex];
                this->heapValues[fatherIndex] = temp;

                temp = this->heapIndexes[index];
                this->heapIndexes[index] = this->heapIndexes[fatherIndex];
                this->heapIndexes[fatherIndex] = temp;


                temp = this->heapPrev[index];
                this->heapPrev[index] = this->heapPrev[fatherIndex];
                this->heapPrev[fatherIndex] = temp;

                heapifyUP(fatherIndex);
            }
    }

     void Heap::heapifyDown(int index) {
            int leftChildIndex = 2 * (index + 1) - 1;
            int rightChildIndex = leftChildIndex +1;
            int smallest = index;

            if (leftChildIndex < this->numOfElements && this->heapValues[leftChildIndex] < this->heapValues[smallest]) {
                smallest = leftChildIndex;
            }

            if (rightChildIndex < this->numOfElements && this->heapValues[rightChildIndex] < this->heapValues[smallest]) {
                smallest = rightChildIndex;
            }

            if (smallest != index) {
                int temp = this->heapValues[index];
                this->heapValues[index] = this->heapValues[smallest];
                this->heapValues[smallest] = temp;

                temp = this->heapIndexes[index];
                this->heapIndexes[index] = this->heapIndexes[smallest];
                this->heapIndexes[smallest] = temp;


                 temp = this->heapPrev[index];
                this->heapPrev[index] = this->heapPrev[smallest];
                this->heapPrev[smallest] = temp;

                heapifyDown(smallest);
            }
        }

    void Heap::push(int value, int index, int prev) {
        if (numOfElements == 0) {
            heapValues[0] = value;
            heapIndexes[0] = index;
            heapPrev[0] = prev;
            numOfElements++;
        } else {
            heapValues[numOfElements] = value;
            heapIndexes[numOfElements] = index;
            heapPrev[numOfElements] = prev;
            heapifyUP(numOfElements);
            numOfElements++;
        }
    }

    Edge Heap::pop() {
        if (numOfElements == 0) {
            throw std::out_of_range("Heap is empty");
        }

        int rootValue = heapValues[0];
        int rootIndex = heapIndexes[0];
        int source = heapPrev[0];

        heapValues[0] = heapValues[numOfElements - 1];
        heapIndexes[0] = heapIndexes[numOfElements - 1];
        heapPrev[0] = heapPrev[numOfElements-1];

        numOfElements--;
        heapifyDown(0);
        return Edge(source, rootIndex, rootValue);
    }

    bool Heap::isEmpty() {
        return numOfElements == 0;
    }

    

    UnionFind::UnionFind(int _value) : value(_value), pointsTo(this) {}

    UnionFind::UnionFind() {}

    UnionFind* UnionFind::find() {
        if (value != pointsTo->value) {
            UnionFind* realPointsTo = pointsTo->find();
            pointsTo = realPointsTo;
        }
        return pointsTo;
    }

    void UnionFind::union_sets(UnionFind* u) {
        UnionFind* root_u = u->find();
        UnionFind* root_v = find();

        if (root_u != root_v) {
            root_u->pointsTo = root_v;
        }
    }

    Graph* Algorithms::BFS(Graph* graph, int src) {
        int numVertices = graph->getNumVertices();
        bool* visited = new bool[numVertices]();
        for (int i = 0; i < numVertices; i++)
        {
            visited[i]=false;
        }
        
        Graph* bfstree = new Graph(graph->getNumVertices());
        Queue queue;



        visited[src] = true;
        queue.enqueue(src,0);

        while (!queue.isempty()) {
            int currnode = queue.deQueue();
            
            Node* adjlist = graph->getAdjList(currnode);

            while (adjlist != nullptr) {
                int neighborvertex = adjlist->vertex;
                if (!visited[neighborvertex]) {
                    visited[neighborvertex] = true;
                    queue.enqueue(neighborvertex,0);
                    bfstree->addEdge(currnode, neighborvertex, adjlist->weight);
                }
                adjlist = adjlist->next;
            }
        }

        return bfstree;
        
    }

    Graph* Algorithms::DFS(Graph* graph, int src) {
         int numVertices = graph->getNumVertices();
        Graph* DFSTree = new Graph(graph->getNumVertices());
        bool* visited = new bool[graph->getNumVertices()]();
        Stack stack;
        for (int i = 0; i < numVertices; i++)
        {
            visited[i]=false;
        }

        visited[src] = true;
        stack.push(src,0);

        while (!stack.isEmpty()) {
            int currnode = stack.pop();
            Node* adjlist = graph->getAdjList(currnode);

            while (adjlist != nullptr) {
                int neighborvertex = adjlist->vertex;

                if (!visited[neighborvertex]) {
                    stack.push(neighborvertex,0);
                    visited[neighborvertex] = true;
                    DFSTree->addEdge(currnode, neighborvertex, adjlist->weight);
                }
                adjlist = adjlist->next;
            }
        }
        return DFSTree;
    }

    Graph* Algorithms::Prim(Graph* graph) {
             int numOfVertices = graph->getNumVertices();
        bool* visited = new bool[numOfVertices]();
        Graph* mst = new Graph(numOfVertices);
        Heap heap(numOfVertices);
         for (int i = 0; i < numOfVertices; i++)
        {
            visited[i]=false;
        }

        visited[0] = true;

       

        Node* currneighbour = graph->getAdjList(0);

        while(currneighbour!= nullptr){
            heap.push(currneighbour->weight,currneighbour->vertex, 0);
            currneighbour=currneighbour->next;

        }
       

      

        while (!heap.isEmpty()) {
            
            Edge curr = heap.pop();
            if (!visited[curr.getDstedge()]) {
                visited[curr.getDstedge()] = true;
                mst->addEdge(curr.srcedge, curr.dstedge, curr.weight);

                 currneighbour = graph->getAdjList(curr.dstedge);
                 while(currneighbour!=nullptr){
                    if(!visited[currneighbour->vertex]){

                    heap.push(currneighbour->weight,currneighbour->vertex,curr.dstedge);

                    }

                    currneighbour = currneighbour->next;


                 }
            }
            
        }

        return mst;
    }

    Graph* Algorithms::Dijkstra(Graph* graph, int src) {
       int numVertices = graph->getNumVertices();
        bool* visited = new bool[numVertices]();  
        int* shortestDist = new int[numVertices];  
        Graph* resultGraph = new Graph(numVertices);  
        Heap heap(numVertices);  
        
       
        for (int i = 0; i < numVertices; i++) {
            shortestDist[i] = INT_MAX;
        }
        shortestDist[src] = 0;  
        
        Node* currNeighbour = graph->getAdjList(src);
        visited[src] = true;  


        while (currNeighbour != nullptr) {
            heap.push(currNeighbour->weight, currNeighbour->vertex, src);
            currNeighbour = currNeighbour->next;
        }

       
        while (!heap.isEmpty()) {
            Edge currEdge = heap.pop();  
            int srcVertex = currEdge.srcedge;
            int dstVertex = currEdge.dstedge;
            int edgeWeight = currEdge.weight;


            if (visited[dstVertex]) continue;


            visited[dstVertex] = true;
            resultGraph->addEdge(srcVertex, dstVertex, edgeWeight);
            

            Node* neighbour = graph->getAdjList(dstVertex);
            while (neighbour != nullptr) {
                int newDist = shortestDist[srcVertex] + neighbour->weight;
                if (!visited[neighbour->vertex] && newDist < shortestDist[neighbour->vertex]) {
                    shortestDist[neighbour->vertex] = newDist;
                    heap.push(neighbour->weight, neighbour->vertex, dstVertex);
                }
                neighbour = neighbour->next;
            }
        }

        delete[] visited;
        delete[] shortestDist;
        return resultGraph;
    }

    Graph* Algorithms::kruskal(Graph* graph) {
        int numVertices = graph->getNumVertices();
        Graph* mst = new Graph(numVertices);
       
        int edgeCount = 0;
        UnionFind* uf  = new UnionFind[numVertices];

        Edge* edges = new Edge[numVertices * numVertices] ;

        for (int i = 0; i < numVertices; i++) {
            Node* adjList = graph->getAdjList(i);
            while (adjList != nullptr) {
                if (i < adjList->vertex) {
                    edges[edgeCount].SetEdge(i,adjList->vertex,adjList->weight);
                    edgeCount++;
                }
                adjList = adjList->next;
            }
        }

        
        for (int i = 0; i < edgeCount - 1; i++) {
            for (int j = 0; j < edgeCount - i - 1; j++) {
                if (edges[j].weight > edges[j + 1].weight) {
                    Edge temp = edges[j];
                    edges[j] = edges[j + 1];
                    edges[j + 1] = temp;
                }
            }
        }

        
        for (int i = 0; i < numVertices; i++) {
            
            uf[i].value=i;
            uf[i].pointsTo = &uf[i];

        }

        
        for (int i = 0; i < edgeCount; i++) {
            Edge edge = edges[i];
            int src = edge.srcedge;
            int dst = edge.dstedge;

            if (uf[src].find() != uf[dst].find()) {
                mst->addEdge(src, dst, edge.weight);
                uf[src].union_sets(&uf[dst]);
            }
        }

        return mst;
    }

}





