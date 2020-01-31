#include <iostream>
#include <vector>
#include "Graph.h"

using namespace std;

int main() {
    Graph graph;

    graph.addEdge({1, 2, 1});
    graph.addEdge({1, 3, 1});
    graph.addEdge({1, 4, 1});
    graph.addEdge({2, 1, 1});
    graph.addEdge({2, 7, 1});
    graph.addEdge({3, 1, 1});
    graph.addEdge({4, 2, 1});
    graph.addEdge({4, 5, 1});
    graph.addEdge({6, 2, 1});
    graph.addEdge({6, 4, 1});
    graph.addEdge({6, 8, 1});
    graph.addEdge({7, 1, 1});
    graph.addEdge({8, 1, 1});
    graph.addEdge({8, 7, 1});

    graph.printEdges();
    graph.printAdjacencyList();
    graph.bfsStartingOn(4);
    graph.printVisitedInfo();

    return 0;
}
