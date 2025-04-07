#include <iostream> 
#include <climits>
#include "Algorithm.h"
#include "Graph.h"


using namespace std;
using namespace graph;

int main() {
    
    Graph* graph = new Graph(5);

    
    graph->addEdge(0, 1, 10);
    graph->addEdge(0, 4, 5);
    graph->addEdge(1, 2, 1);
    graph->addEdge(1, 4, 2);
    graph->addEdge(2, 3, 4);
    graph->addEdge(3, 4, 9);

    
    cout << "Original Graph: " << endl;
    graph->print_graph();

    
    cout << "\nBFS ,starting from src vertex : " << endl;
     Algorithms algo;  
    Graph* bfsTree = algo.BFS(graph, 0);
    bfsTree->print_graph();

    
     cout << "\nDFS ,starting from src vertex : " << endl;
       
     Graph* dfsTree = algo.DFS(graph, 0);
     dfsTree->print_graph();

    
     cout << "\nPrim's Algorithm : " << endl;
       
     Graph* mstPrim = algo.Prim(graph);
     mstPrim->print_graph();

   
    cout << "\nDijkstra's Algorithm ,starting from src vertex : " << endl;
    
    Graph* shortestPaths = algo.Dijkstra(graph, 0);
    shortestPaths->print_graph();

    
     cout << "\nKruskal's Algorithm ,Minimum Spanning Tree: " << endl;
     Graph* mstKruskal = algo.kruskal(graph);
     mstKruskal->print_graph();

   



    
    delete graph;
    delete bfsTree;
    delete dfsTree;
    delete mstPrim;
    delete shortestPaths;
    delete mstKruskal;

    return 0;
}



