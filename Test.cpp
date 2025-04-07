#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <stdexcept>
#include <limits.h> 
#include "Graph.h" 
#include "Algorithm.h"
using namespace graph;



TEST_CASE("Graph class functionality") {
    Graph graph(5);  

    
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 4, 20);
    graph.addEdge(1, 2, 30);
    graph.addEdge(3, 4, 40);
    
    
    graph.print_graph();

    
    CHECK(graph.getNumVertices() == 5);

    
    graph.removeEdge(0, 1);
    graph.removeEdge(3, 4);
    
   
    CHECK_NOTHROW(graph.getAdjList(0));
    CHECK_NOTHROW(graph.getAdjList(1));

    CHECK_THROWS(graph.removeEdge(0, 100));  
}

TEST_CASE("Queue class functionality") {
    Queue queue;

    
    queue.enqueue(1, 10);
    queue.enqueue(2, 20);
    queue.enqueue(3, 30);
    
    CHECK(queue.deQueue() == 1);  
    CHECK(queue.deQueue() == 2); 
    CHECK(queue.deQueue() == 3);  
    CHECK(queue.deQueue() == -1); 

   
    CHECK(queue.isempty() == true);
}

TEST_CASE("Stack class functionality") {
    Stack stack;

    
    stack.push(1, 10);
    stack.push(2, 20);
    stack.push(3, 30);

    CHECK(stack.pop() == 3);   
    CHECK(stack.pop() == 2);   
    CHECK(stack.pop() == 1);   
    CHECK(stack.pop() == -1); 

    
    CHECK(stack.isEmpty() == true);
}

TEST_CASE("Heap class functionality") {
    Heap heap(10);

    
     heap.push(10, 0, -1);  
    heap.push(20, 1, 0);   
    heap.push(5, 2, 1);    
    heap.push(15, 3, 2);   
    heap.push(30, 4, 3);   

     Edge edge1 = heap.pop();
    CHECK(edge1.weight == 5);  
    CHECK(edge1.srcedge == 2);  
    CHECK(edge1.dstedge == 0);  

    Edge edge2 = heap.pop();
    CHECK(edge2.weight == 10);  
    CHECK(edge2.srcedge == 0);
    CHECK(edge2.dstedge == 0);

    Edge edge3 = heap.pop();
    CHECK(edge3.weight == 15);  
    CHECK(edge3.srcedge == 3);
    CHECK(edge3.dstedge == 0);

    Edge edge4 = heap.pop();
    CHECK(edge4.weight == 20);  
    CHECK(edge4.srcedge == 1);
    CHECK(edge4.dstedge == 0);

    Edge edge5 = heap.pop();
    CHECK(edge5.weight == 30);  
    CHECK(edge5.srcedge == 4);
    CHECK(edge5.dstedge == 0);

     

    CHECK_THROWS(heap.pop()); 
}


TEST_CASE("UnionFind class functionality") {
    UnionFind uf1(1);
    UnionFind uf2(2);
    UnionFind uf3(3);
    
   
    CHECK(uf1.find() != uf2.find());
    CHECK(uf1.find() != uf3.find());
    CHECK(uf2.find() != uf3.find());

    uf1.union_sets(&uf2);  
    CHECK(uf1.find() == uf2.find());

    uf2.union_sets(&uf3);  
    CHECK(uf1.find() == uf3.find());
}

TEST_CASE("Algorithms class functionality") {
    Graph graph(5);

   
    graph.addEdge(0, 1, 10);
    graph.addEdge(0, 2, 20);
    graph.addEdge(1, 3, 30);
    graph.addEdge(2, 4, 40);
    
    Algorithms algo;
    Graph* bfstree = algo.BFS(&graph, 0);
    
    CHECK_NOTHROW(bfstree->print_graph());  

    
    Graph* dfstree = algo.DFS(&graph, 0);
    CHECK_NOTHROW(dfstree->print_graph());  

   
    
    Graph* dijkstraTree = algo.Dijkstra(&graph,0);
    CHECK_NOTHROW(dijkstraTree->print_graph()); 

   
    Graph* mst = algo.kruskal(&graph);
    CHECK_NOTHROW(mst->print_graph());  
}
