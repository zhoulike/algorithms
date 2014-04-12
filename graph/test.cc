#include <iostream>
#include <string>
#include "graph.h"

using namespace std;

void visit(int vertex)
{
    cout << vertex << endl;
}

void bfs_test_undirected()
{
    Graph g(Graph::UNDIRECTED);
    g.AddEdge(0, 1);
    g.AddEdge(0, 4);
    g.AddEdge(1, 5);
    g.AddEdge(2, 3);
    g.AddEdge(2, 5);
    g.AddEdge(2, 6);
    g.AddEdge(3, 6);
    g.AddEdge(3, 7);
    g.AddEdge(5, 6);
    g.AddEdge(6, 7);

    g.BFS(1, visit);

    g.RemoveEdge(2, 5);
    g.BFS(1, visit);
}

void dfs_test_directed()
{
    cout << "test DFS:" << endl;

    Graph g;
    g.AddEdge(0, 1);
    g.AddEdge(0, 3);
    g.AddEdge(1, 4);
    g.AddEdge(2, 4);
    g.AddEdge(2, 5);
    g.AddEdge(3, 1);
    g.AddEdge(4, 3);
    g.AddEdge(5, 5);

    g.DFS(visit);
}

int main(int argc, char *argv[])
{
    bfs_test_undirected();    
    dfs_test_directed();    
    return 0;
}
