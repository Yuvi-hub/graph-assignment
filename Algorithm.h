#include <iostream>
#include <stdexcept>
#include <limits.h>
#include "Graph.h"
using namespace std;
using namespace graph;

namespace graph
{

    class Queue
    {
    private:
        Node *head;
        Node *tail;
        int size;

    public:
        Queue();

        ~Queue();

        void enqueue(int vertex, int weight);

        int deQueue();

        bool isempty();
    };

    class Stack
    {
    private:
        Node *head;
        int size;

    public:
        Stack();

        ~Stack();

        int pop();

        void push(int vertex, int weight);

        bool isEmpty();
    };

    class Edge
    {
    public:
        int srcedge;
        int dstedge;
        int weight;

        Edge(int srcedge, int dstedge, int weight);
        Edge();

        void SetEdge(int srcedge, int dstedge, int weight);

        int getDstedge();
    };

    class Heap
    {
    private:
        int size;
        int *heapValues;
        int *heapIndexes;
        int *heapPrev;
        int numOfElements;

        void heapifyUP(int index);

        void heapifyDown(int index);

    public:
        Heap(int size);

        ~Heap();

        void push(int value, int index, int prev);

        Edge pop();

        bool isEmpty();
    };

    class UnionFind
    {
    public:
        int value;
        UnionFind *pointsTo;

        UnionFind(int _value);
        UnionFind();

        UnionFind *find();

        void union_sets(UnionFind *u);
    };

    class Algorithms
    {

    public:
        Graph *BFS(Graph *graph, int src);

        Graph *DFS(Graph *graph, int src);

        Graph *Prim(Graph *graph);

        Graph *Dijkstra(Graph *graph, int src);

        Graph *kruskal(Graph *graph);
    };

}
