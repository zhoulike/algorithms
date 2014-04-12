#ifndef GRAPH_H
#define GRAPH_H

#include <vector>

class Graph
{
public:
    enum DiscoverType {
        WHITE, //undiscovered vertex
        GRAY,  //discovered vertex, but may have adjacent white vertices
        BLACK  //discovered vertex, and all adjacent vertices have discovered
    };
    enum EdgeType {UNDIRECTED, DIRECTED};

    Graph (EdgeType type = DIRECTED) :type_(type) {};
    //virtual ~Graph ();

    void AddEdge(int u, int v, int weight = 1);  //assume no zero weighted edge
    void RemoveEdge(int u, int v);

    void BFS(int source, void (*visit)(int) = visit_);

private:
    EdgeType type_;  //undirected or directed
    std::vector<std::vector<int> > adj_matrix;

    //used by BFS
    std::vector<int> bfs_parent;  //parent in the breadth-first tree
    std::vector<int> bfs_distance;  //distance from source node

    //default visit function: do nothing
    static void visit_(int vertex) {};
};

#endif
