//Solution1: Memory Limit Exceeded
//build a graph and use bfs to find the transformation
class Solution {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 0;
        else if (changeable(start, end))  //one transformation, two words
            return 2;

        dict.insert(start);
        dict.insert(end);
        create_graph(dict);
        return bfs(node[start], node[end]);
    }
private:
    bool changeable(string from, string to)
    {
        int count = 0;
        for (int i = 0; i < from.size(); ++i)
            if (from[i] != to[i])
                ++count;
        return count == 1;
    }

    void create_graph(unordered_set<string> &dict)
    {
        graph = vector<vector<int>>(dict.size(), vector<int>(dict.size(), 0));
        int num = 0;
        for (string word: dict)
            node[word] = num++;

        for (string from: dict) {
            for (string to: dict) {
                if (changeable(from, to))
                    graph[node[from]][node[to]] = 1;
            }
        }
    }

    int bfs(int start, int end)
    {
        queue<int> q;
        q.push(start);
        q.push(-1);
        vector<bool> visited(node.size(), false);
        visited[start] = true;
        int steps = 1;

        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            if (cur == -1 && !q.empty()) {
                ++steps;
                q.push(-1);
            } else {
                for (int j = 0; j < graph.size(); ++j) {
                    if (graph[cur][j] && !visited[j]) {
                        if (j == end)
                            return steps + 1;
                        visited[j] = true;
                        q.push(j);
                    }
                }
            }
        }
        return 0;
    }

    vector<vector<int>> graph;
    unordered_map<string, int> node;
};

//Optimized Solution2: Time Limit Exceeded
//a dict has 2855 elements, it runs 2.89s
//using a variation of adjacency list, not adjacency matrix
class Solution2 {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 0;
        else if (changeable(start, end))
            return 2;

        dict.insert(start);
        dict.insert(end);
        create_graph(dict);
        return bfs(start, end);
    }
private:
    bool changeable(string from, string to)
    {
        int count = 0;
        for (int i = 0; i < from.size(); ++i)
            if (from[i] != to[i])
                ++count;
        return count == 1;
    }

    void create_graph(unordered_set<string> &dict)
    {
        for (string word: dict)
            graph[word] = vector<string>();

        for (string from: dict) {
            for (string to: dict) {
                if (changeable(from, to))
                    graph[from].push_back(to);
            }
        }
    }

    int bfs(string start, string end)
    {
        queue<string> q;
        q.push(start);
        q.push("");
        unordered_set<string> visited;
        visited.insert(start);
        int steps = 1;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            if (cur == "" && !q.empty()) {
                ++steps;
                q.push("");
            } else {
                for (string next: graph[cur]) {
                    if (visited.find(next) == visited.end()) {
                        if (next == end)
                            return steps + 1;
                        visited.insert(next);
                        q.push(next);
                    }
                }
            }
        }
        return 0;
    }

    unordered_map<string, vector<string>> graph;
};

//Optimized Solution3: Accept (1060ms)
//Do not need to build a graph, just simulate one.
class Solution3 {
public:
    int ladderLength(string start, string end, unordered_set<string> &dict) {
        if (start == end)
            return 0;

        queue<string> q;
        q.push(start);
        q.push("");
        dict.erase(start);
        dict.insert(end);
        int steps = 1;  //first arrow: start->
        
        while (!q.empty()) {
            string curr = q.front();
            q.pop();

            if (curr == "" && !q.empty()) { //level end
                ++steps;
                q.push("");
            } else {
                for (int i = 0; i < curr.size(); ++i) {
                    for (char ch = 'a'; ch <= 'z'; ++ch) {
                        string tmp = curr;
                        tmp[i] = ch;
                        auto iter = dict.find(tmp);
                        if (iter != dict.end()) {
                            if (*iter == end)
                                return steps + 1;  //arrow number plus 1. start->end: 1 arrow, 2 words
                            q.push(*iter);
                            dict.erase(iter);
                        }
                    }
                }
            }
        }
        return 0;
    }
};
