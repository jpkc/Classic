#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>

typedef int nodeId;
typedef int Weight;
typedef std::unordered_set<nodeId> List;
typedef std::unordered_map<nodeId, List> AdjacencyList;

class Path {
public:
    Weight totalCost;
    std::vector<nodeId> nodesPath;
    friend std::ostream &operator<<(std::ostream &os, const Path &edge);
};

class Edge
{
public:
    nodeId from;
    nodeId to;
    Weight weight;
    Edge(nodeId from, nodeId to, int weight) : from{from}, to{to}, weight{weight} {};
    inline bool operator==(const Edge &edge) const {return (from == edge.from) && (to == edge.to);}
    friend std::ostream &operator<<(std::ostream &os, const Edge &edge);
};

typedef std::unordered_set<Edge> Edges;

template<>
struct std::hash<Edge>
{
    size_t
    operator()(const Edge & obj) const
    {
        return hash<int>()(obj.from + obj.to*65536);
    }
};

typedef struct{
    nodeId from;
    Weight totalCost;
} Visit;

class Graph
{
    Edges edges;
    AdjacencyList adjacencyList;

public:
    bool addEdge(Edge edge);
    void printEdges();
    void printAdjacencyList();
    void printVisitedInfo();
    void bfsStartingOn(nodeId node);
    Path shortestPath(nodeId nodeStart, nodeId nodeEnd);
//    Path cycleStartingOn(nodeId node);

private:
    std::unordered_map<nodeId, Visit> visited;
    void adjacencyInsert(Edge edge);
    void buildAdjacencyList();
    void processAdjacencyQueue(std::queue<nodeId> &bfsQueue);
    Path tracePath(nodeId nodeStart, nodeId nodeEnd);
};

#endif //GRAPH_H
