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
    graph.addEdge({2, 4, 1});
    graph.addEdge({2, 7, 1});
    graph.addEdge({3, 1, 1});
    graph.addEdge({4, 2, 1});
    graph.addEdge({4, 5, 1});
    graph.addEdge({5, 11, 1});
    graph.addEdge({6, 2, 1});
    graph.addEdge({6, 4, 100});
    graph.addEdge({6, 8, 1});
    graph.addEdge({7, 1, 1});
    graph.addEdge({8, 1, 1});
    graph.addEdge({8, 7, 1});
    graph.addEdge({11, 5, 1});
    graph.addEdge({11, 17, 1});
    graph.addEdge({12, 14, 1});
    graph.addEdge({13, 17, 1});
    graph.addEdge({14, 6, 1});
    graph.addEdge({14, 7, 1});
    graph.addEdge({17, 13, 1});
    graph.addEdge({17, 12, 1});

    graph.printEdges();
    graph.printAdjacencyList();

    nodeId startNode = 13;
    nodeId endNode = 4;
    Path path = graph.shortestPath(startNode, endNode);
//    graph.printVisitedInfo();
    cout << "Path from " << startNode << " to " << endNode << ": "<< path << endl;

    startNode = 5;
    endNode = 15;
    path = graph.shortestPath(startNode, endNode);
//    graph.printVisitedInfo();
    cout << "Path from " << startNode << " to " << endNode << ": "<< path << endl;

    startNode = 7;
    endNode = 6;
    path = graph.shortestPath(startNode, endNode);
//    graph.printVisitedInfo();
    cout << "Path from " << startNode << " to " << endNode << ": "<< path << endl;

    startNode = 3;
    endNode = 12;
    path = graph.shortestPath(startNode, endNode);
//    graph.printVisitedInfo();
    cout << "Path from " << startNode << " to " << endNode << ": "<< path << endl;

    startNode = endNode = 14;
    path = graph.shortestPath(startNode, startNode);
//    graph.printVisitedInfo();
    cout << "Path from " << startNode << " to " << endNode << ": "<< path << endl;
//    cout << "Cycle from " << startNode << ":" <<  endl;
//    Path cycle = graph.cycleStartingOn(startNode);
//    cout << cycle << endl;

    return 0;
}
