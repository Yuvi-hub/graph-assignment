#include <iostream>
#include <stdexcept> 
#include "Graph.h" 

using namespace std;
using namespace graph;

namespace graph {

    Graph::Graph(int vertices) {
        numVertices = vertices;
        adjList = new Node*[numVertices];  
        for (int i = 0; i < numVertices; i++) {
            adjList[i] = nullptr;  
        }
    }

    int Graph::getNumVertices() {
        return this->numVertices;
    }

    Node* Graph::getAdjList(int v) {
        return this->adjList[v];
    }

    Graph::~Graph() {
        for (int i = 0; i < numVertices; i++) {
            Node* current = adjList[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] adjList;
    }

    void Graph::addEdge(int src, int dst, int weight) {
        if (src < 0 || src >= numVertices || dst < 0 || dst >= numVertices) {
            throw runtime_error("Invalid vertex index.");
        }

        Node* newNode = new Node(src, weight);
        newNode->next = adjList[dst];
        adjList[dst] = newNode;

        newNode = new Node(dst, weight);
        newNode->next = adjList[src];
        adjList[src] = newNode;
    }

    void Graph::removeEdge(int src, int dst) {
        if (adjList[src] == nullptr || adjList[dst] == nullptr) {
            throw runtime_error("Edge does not exist.");
        }

        Node* prev = nullptr;
        Node* current = adjList[src];
        while (current != nullptr   && current->vertex != dst) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            if (prev == nullptr) {
                adjList[src] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
        }

        prev = nullptr;
        current = adjList[dst];
        while (current != nullptr && current->vertex != src) {
            prev = current;
            current = current->next;
        }
        if (current != nullptr) {
            if (prev == nullptr) {
                adjList[dst] = current->next;
            } else {
                prev->next = current->next;
            }
            delete current;
        }
    }

    void Graph::print_graph() {
        for (int i = 0; i < numVertices; i++) {
            cout << "Vertex " << i << ": ";
            Node* current = adjList[i];
            while (current != nullptr) {
                cout << "(" << current->vertex << ", " << current->weight << ") ";
                current = current->next;
            }
            cout << endl;
        }
    }
}





