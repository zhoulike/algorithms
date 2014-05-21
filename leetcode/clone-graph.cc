/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (!node)
            return NULL;
            
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> hash_map;
        unordered_set<UndirectedGraphNode*> visited;
        queue<UndirectedGraphNode*> q;

        UndirectedGraphNode *head = new UndirectedGraphNode(node->label);
        hash_map[node] = head;
        q.push(node);

        while (!q.empty()) {
            auto nd = q.front();
            q.pop();
            if (visited.find(nd) == visited.end())
                visited.insert(nd);
            else
                continue;

            for (auto nbs: nd->neighbors) {
                UndirectedGraphNode *tmp;
                auto iter = hash_map.find(nbs);
                if (iter == hash_map.end()) {
                    tmp = new UndirectedGraphNode(nbs->label);
                    hash_map[nbs] = tmp;
                } else
                    tmp = iter->second;
                hash_map[nd]->neighbors.push_back(tmp);
                q.push(nbs);
            }
        }
        
        return head;
    }
};

//{0,1,2#1,2#2,2}
//assume node's label is 0~9
UndirectedGraphNode* create_graph(string serialized) {
    if (serialized.size() == 2) //{}
        return NULL;

    string::const_iterator iter = serialized.begin() + 1;
    UndirectedGraphNode *head = new UndirectedGraphNode(*iter++ - '0');
    UndirectedGraphNode* pos = head;
    unordered_map<int, UndirectedGraphNode*> hash_map;
    hash_map[head->label] = head;

    while (iter != serialized.end() && *iter != '}') {
        if (*iter == ',')
            ++iter;
        else if (*iter == '#') {
            ++iter;
            pos = hash_map[*iter - '0'];
            ++iter;
        }
        else {
            int val = *iter++ - '0';
            auto ret = hash_map.find(val);
            UndirectedGraphNode *tmp = NULL;
            if (ret == hash_map.end()) {
                tmp = new UndirectedGraphNode(val);
                hash_map[val] = tmp;
            } else
                tmp = ret->second;
            pos->neighbors.push_back(tmp);
        }
    }
    return head;
}

void serialize(UndirectedGraphNode *node) {
    if (!node)
        return;

    queue<UndirectedGraphNode*> q;
    unordered_set<UndirectedGraphNode*> visited;
    q.push(node);
    while (!q.empty()) {
        auto nd = q.front();
        q.pop();
        if (visited.find(nd) == visited.end())
            visited.insert(nd);
        else
            continue;
        cout << nd->label;

        for (auto nbs: nd->neighbors) {
            cout << ',' << nbs->label;
            q.push(nbs);
        }
        cout << '#';
    }
    cout << endl;
}
