#include <iostream>
#include <stdexcept>
#ifndef GRAPH_H
#define GRAPH_H
using namespace std;

namespace graph
{

    struct Node
    {
        int vertex;
        int weight;
        Node *next;

       Node(int v, int w) : vertex(v), weight(w), next(nullptr) {}
    };
    class Graph
    {
    private:
        Node **adjList;
        int numVertices;

    public:
        Graph(int vertices);

        int getNumVertices();

        Node *getAdjList(int v);

        ~Graph();

        void addEdge(int src, int dst, int weight);

        void removeEdge(int src, int dst);

        void print_graph();
    };
}
#endif