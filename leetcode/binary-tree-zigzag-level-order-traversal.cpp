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