#include "Graph.h"
#include <iostream>
#include <algorithm>

using namespace std;

std::ostream& operator<<(std::ostream& os, const Edge& edge)
{
    os << edge.from << "->" << edge.to << ":\t" << edge.weight;
    return os;
}

std::ostream& operator<<(std::ostream& os, const Path& path) {
    os << "Path Total Cost: " << path.totalCost << ". Path nodes: ";
    for (auto i = 0; i < path.nodesPath.size(); ++i) {
        if(i)
            os << ", ";
        os << path.nodesPath[i];
    }
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

void Graph::printEdges()
{
    cout << "Edges: Weights";
    for(auto edge : edges)
        cout << endl << edge;
    cout << endl;
}

void Graph::buildAdjacencyList()
{
    adjacencyList.clear();
    for(auto edge : edges)
        adjacencyInsert(edge);
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

void Graph::printAdjacencyList()
{
    buildAdjacencyList();
    cout << "Adjacency list: " << endl;
    for(auto const &list: adjacencyList) {
        cout << list.first << ":\t";
        for(auto it = list.second.begin(); it != list.second.end(); ++it) {
            if(it != (list.second).begin())
                cout << ", ";
            cout << *it;
        }
        cout << endl;
    }
}

void Graph::printVisitedInfo() {
    cout << "Visited node: visited from, visit cost" << endl;
    for(auto edge : visited) {
        cout << edge.first << ":\t" << edge.second.from << ",\t" << edge.second.totalCost;
        if(edge.first == edge.second.from)
            cout << " << Starting node";
        cout  << endl;
    }
}

void Graph::bfsStartingOn(nodeId node)
{
    queue<nodeId> bfs;
    bfs.push(node);
    visited.clear();
    visited.insert({node, {node, 0}});
    while(!bfs.empty())
        processAdjacencyQueue(bfs);
}

void Graph::processAdjacencyQueue(std::queue<nodeId> &bfsQueue)
{
    nodeId currentNode = bfsQueue.front();
    Weight currentCost = visited.find(currentNode)->second.totalCost;
    bfsQueue.pop();

    auto adjacency = adjacencyList.find(currentNode);
    for(auto adjacentNode : adjacency->second) {
        auto edge = edges.find({currentNode, adjacentNode, 0});
        Weight edgeCost = edge->weight;
        auto nodePosition = visited.find(adjacentNode);
        if(nodePosition == visited.end()) {
            bfsQueue.push(adjacentNode);
            visited.insert({adjacentNode, {currentNode, currentCost + edgeCost}});
        }
        else {
            if((currentCost + edgeCost) < nodePosition->second.totalCost) {
                bfsQueue.push({adjacentNode});
                visited.erase(currentNode);
                visited.insert({adjacentNode, {currentNode, currentCost + edgeCost}});
            }
        }
    }
}

Path Graph::shortestPath(nodeId nodeStart, nodeId nodeEnd)
{
//    if(nodeStart == nodeEnd)
//        return cycleStartingOn(nodeStart);

    return tracePath(nodeStart, nodeEnd);
}

//Path Graph::cycleStartingOn(nodeId nodeStart)
//{
//    Path path;
//    bfsStartingOn(nodeStart);
//    for(auto visitedNode : visited) {
//        if(visitedNode.first != nodeStart) {
//            auto visitedNodeAdjacencyList = adjacencyList.find(visitedNode.first);
//            auto linkNode = visitedNodeAdjacencyList->second.find(nodeStart);
//            if(linkNode != visitedNodeAdjacencyList->second.end()) {
//                path = tracePath(nodeStart, visitedNode.first);
//                reverse(path.nodesPath.begin(),path.nodesPath.end());
//                path.nodesPath.push_back(nodeStart);
//                path.totalCost += edges.find({visitedNode.first, nodeStart, 0})->weight;
//            }
//        }
//    }
//    return path;
//}

Path Graph::tracePath(nodeId nodeStart, nodeId nodeEnd)
{
    bfsStartingOn(nodeStart);

    Path path;
    auto currentNode = visited.find(nodeEnd);
    if(currentNode != visited.end()) {
        path.totalCost = currentNode->second.totalCost;
        do {
            path.nodesPath.push_back(nodeEnd);
            if(nodeEnd == currentNode->second.from)
                break;
            nodeEnd = currentNode->second.from;
            currentNode = visited.find(nodeEnd);
        } while(nodeEnd != nodeStart);
        path.nodesPath.push_back(nodeStart);
    }
    reverse(path.nodesPath.begin(),path.nodesPath.end());
    return path;
}

