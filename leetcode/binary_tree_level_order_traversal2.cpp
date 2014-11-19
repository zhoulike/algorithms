/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree {3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7]
  [9,20],
  [3],
]
*/

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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        int level = 0;
        vector<pair<TreeNode*, int> > queue;
        vector<vector<int> > v;
        
        if(!root)
            return v;
            
        queue.push_back(make_pair(root, level));
        for(auto i = 0; i != queue.size(); ++i){
			if(v.size() == queue[i].second)
			   v.resize(queue[i].second + 1);
            v[queue[i].second].push_back((queue[i].first)->val);
            
            if((queue[i].first)->left)
                queue.push_back(make_pair((queue[i].first)->left, queue[i].second + 1));
			
            if((queue[i].first)->right)
                queue.push_back(make_pair((queue[i].first)->right, queue[i].second + 1));
        }
        
        return vector<vector<int> >(v.rbegin(), v.rend());
    }
};

class Solution {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
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
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
