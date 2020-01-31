#include "Graph.h"
#include <iostream>

using namespace std;

std::ostream& operator<<(std::ostream& os, const Edge& edge)
{
    os << edge.from << "->" << edge.to << ": " << edge.weight;
    return os;
}

bool Graph::addEdge(Edge edge)
{
    auto formerEdge = edges.find(edge);
    if (formerEdge != edges.end()) {
        edges.erase(formerEdge);
        edges.insert(edge);
        return false;
    }
    edges.insert(edge);
    return true;
}

void Graph::adjacencyInsert(Edge edge)
{
    auto list = adjacencyList.find(edge.to);
    if( list == adjacencyList.end()) {
        adjacencyList.insert({edge.to, List {}});
    }

    list = adjacencyList.find(edge.from);
    if( list == adjacencyList.end()) {
        adjacencyList.insert({edge.from, List {edge.to}});
    }
    else
        list->second.insert(edge.to);
}

void Graph::buildAdjacencyList()
{
    adjacencyList.clear();
    for(auto edge : edges)
        adjacencyInsert(edge);
}

void Graph::printEdges()
{
    cout << "Edges: Weights";
    for(auto edge : edges)
        cout << endl << edge;
    cout << endl;
}

void Graph::printAdjacencyList()
{
    buildAdjacencyList();
    cout << "Adjacency list: " << endl;
    for(auto const &list: adjacencyList) {
        cout << list.first << ": ";
        for(auto it = list.second.begin(); it != list.second.end(); ++it) {
            if(it != (list.second).begin())
                cout << ", ";
            cout << *it;
        }
        cout << endl;
    }
}

void Graph::printVisitedAndRespectiveCost() {
    cout << "Visited node: node visit cost" << endl;
    for(auto edge : visited) {
        cout << edge.first << ": " << edge.second << endl;
    }
}


void Graph::bfsStartingOn(nodeId start)
{
    queue<nodeId> bfs;
    bfs.push(start);
    visited.insert({start, 0});
    while(!bfs.empty())
        processAdjacencyQueue(bfs);
}

void Graph::processAdjacencyQueue(std::queue<nodeId> &bfsQueue)
{
    nodeId currentNode = bfsQueue.front();
    Weight currentCost = visited.find(currentNode)->second;
    bfsQueue.pop();

    auto adjacency = adjacencyList.find(currentNode);
    for(auto adjacentNode : adjacency->second) {
        auto edge = edges.find({currentNode, adjacentNode, 0});
        Weight edgeCost = edge->weight;
        auto nodePosition = visited.find(adjacentNode);
        if(nodePosition == visited.end()) {
            bfsQueue.push(adjacentNode);
            visited.insert({adjacentNode, currentCost + edgeCost});
        }
        else {
            if(currentCost + edgeCost < nodePosition->second) {
                bfsQueue.push({adjacentNode});
                visited.erase(currentNode);
                visited.insert({adjacentNode, currentCost + edgeCost});
            }
        }
    }
}
