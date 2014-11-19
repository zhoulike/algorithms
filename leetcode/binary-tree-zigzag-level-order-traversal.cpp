/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        deque<TreeNode *> q;
        vector<vector<int> > vv;
        
        if (root)
            q.push_back(root);
            
        while (!q.empty()) {
            vector<int> v;
            for (deque<TreeNode *>::iterator first = q.begin(), last = q.end(); first != last; ++first) {
                if ((*first)->left) 
                    q.push_back((*first)->left);
                if ((*first)->right)
                    q.push_back((*first)->right);
                
                v.push_back((*first)->val);
                q.pop_front();
            }
            vv.push_back(v);
        }
        
        for (int i = 0; i < vv.size(); ++i) {
            if (i % 2)
                reverse(vv[i].begin(), vv[i].end());
        }
        
        return vv;
    }
};

class Solution {
public:
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int>> ans;

        if (root) {
            queue<TreeNode*> q;
            TreeNode *sentinel = new TreeNode(0);
            vector<int> this_line;
            q.push(root);
            q.push(sentinel);

            while (!q.empty()) {
                auto curr = q.front();
                q.pop();
                if (curr == sentinel) {
                    if (!this_line.empty()) {
                        ans.push_back(this_line);
                        this_line.clear();
                    }
                    if (!q.empty())
                        q.push(sentinel);
                } else {
                    this_line.push_back(curr->val);
                    if (curr->left)
                        q.push(curr->left);
                    if (curr->right)
                        q.push(curr->right);
                }
            }
        }

        for (int i = 0; i < ans.size(); ++i) {
            if (i % 2 == 1)
                reverse(ans[i].begin(), ans[i].end());
        }

        return ans;
    }
};
