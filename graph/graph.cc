#include "graph.h"
#include <iostream>
#include <queue>

using namespace std;

void Graph::AddEdge(int u, int v, int weight)
{
    if (u < 0 || v < 0)
        return;

    if (u >= adj_matrix.size() || v >= adj_matrix.size()) {
        adj_matrix.resize(max(u, v) + 1);
        for (int i = 0; i < adj_matrix.size(); ++i)
            adj_matrix[i].resize(max(u, v) + 1);
    }

    adj_matrix[u][v] = weight;
    if (type_ == UNDIRECTED)
        adj_matrix[v][u] = weight;
}

void Graph::RemoveEdge(int u, int v)
{
    int vertexs = adj_matrix.size();  //n vertexs: 0, 1, 2, 3, ..., n - 1
    if (u >= 0 && u < vertexs && v >= 0 && v < vertexs) {
        adj_matrix[u][v] = 0;  //do not shrink
        if (type_ == UNDIRECTED)
            adj_matrix[v][u] = 0;
    }
}

void Graph::BFS(int source, void (*visit)(int))
{
    int vertexs = adj_matrix.size();
    if (vertexs == 0 || source < 0 || source >= vertexs)
        return;

    if (bfs_parent.size() != adj_matrix.size()) {
        bfs_parent.resize(adj_matrix.size());
        bfs_distance.resize(adj_matrix.size());
    }

    vector<int> color(vertexs, WHITE);
    for (int i = 0; i < vertexs; ++i)
        bfs_parent[i] = bfs_distance[i] = 0;
    
    queue<int> q_vertex;

    color[source] = GRAY;
    q_vertex.push(source);
    visit(source);

    while (!q_vertex.empty()) {
        int v = q_vertex.front();
        q_vertex.pop();

        for (int i = 0; i < adj_matrix[v].size(); ++i) {
            if (adj_matrix[v][i] && color[i] == WHITE) {
                visit(i);
                color[i] = GRAY;
                q_vertex.push(i);
                bfs_parent[i] = v;
                bfs_distance[i] = bfs_distance[v] + 1;
            } 
        }

        color[v] = BLACK;
    }
}

void Graph::DFS(void (*visit)(int))
{
    int vertexs = adj_matrix.size();

    if (dfs_parent.size() != adj_matrix.size()) {
        dfs_parent.resize(adj_matrix.size());
        dfs_discovered.resize(adj_matrix.size());
        dfs_finished.resize(adj_matrix.size());
    }

    vector<int> color(vertexs, WHITE);
    for (int i = 0; i < vertexs; ++i)
        dfs_parent[i] = dfs_discovered[i] = dfs_finished[i] = 0;
    
    int timestamp = 0;

    for (int i = 0; i < vertexs; ++i) {
        if (color[i] == WHITE) {
            DFS_visit(i, color, timestamp, visit);
        }
    } 
}

void Graph::DFS_visit(int source, vector<int> &color, int &timestamp, void (*visit)(int))
{
    color[source] = GRAY;
    dfs_discovered[source] = ++timestamp;
    visit(source);

    for (int i = 0; i < adj_matrix[i].size(); ++i) {
        if (adj_matrix[source][i] && color[i] == WHITE) {
            dfs_parent[i] = source;
            DFS_visit(i, color, timestamp, visit);
        }
    }    

    color[source] = BLACK;
    dfs_finished[source] = ++timestamp;
}
