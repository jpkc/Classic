#ifndef GRAPH_H
#define GRAPH_H

#include <unordered_set>
#include <unordered_map>
#include <queue>

typedef int nodeId;
typedef int Weight;
typedef std::unordered_set<nodeId> List;
typedef std::unordered_map<nodeId, List> AdjacencyList;

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

class Graph
{
    Edges edges;
    AdjacencyList adjacencyList;

public:
    bool addEdge(Edge edge);
    void printEdges();
    void printAdjacencyList();
    void printVisitedAndRespectiveCost();
    void bfsStartingOn(nodeId start);

private:
    void adjacencyInsert(Edge edge);
    void buildAdjacencyList();
    std::unordered_map<nodeId, int> visited;
    void processAdjacencyQueue(std::queue<nodeId> &bfsQueue);
};

#endif //GRAPH_H
