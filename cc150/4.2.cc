#include <iostream>
#include <vector>
#include <queue>
#include <cassert>

using namespace std;

bool hasRoute(vector<vector<int>> graph, int start, int end)
{
    if (start == end)
        return true;

    size_t nodes = graph.size();
    if (start < 0 || start >= nodes || end < 0 || end >= nodes)
        return false;

    vector<bool> visited(graph.size(), false); //Three color is better
    queue<int> q;
    q.push(start);
    visited[start] = true;

    while (!q.empty()) {
        int node = q.front();
        q.pop();
        for (int i = 0; i < nodes; ++i) {
            if (graph[node][i] != 0 && visited[i] == false) {
                if (i == end)
                    return true;
                q.push(i);
            }
        }
    }
    return false;
}

int main(int argc, char *argv[])
{
    //0->1
    vector<vector<int>> graph1 = {
        {0, 1},
        {0, 0}
    };

    assert(hasRoute(graph1, 0, 0));
    assert(hasRoute(graph1, 1, 1));
    assert(hasRoute(graph1, 0, 1));
    assert(!hasRoute(graph1, 1, 0));
    assert(!hasRoute(graph1, 0, 1000));

    /*
     *0->1->2
     *   |
     *   v
     *   3    4
     */
    vector<vector<int>> graph2 = {
        {0, 1, 0, 0, 0},
        {0, 0, 1, 1, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0},
    };

    assert(hasRoute(graph2, 0, 1));
    assert(hasRoute(graph2, 0, 2));
    assert(hasRoute(graph2, 0, 3));
    assert(!hasRoute(graph2, 0, 4));
    assert(hasRoute(graph2, 1, 3));
    assert(!hasRoute(graph2, 4, 0));

    cout << "All passed!" << endl;
    return 0;
}
