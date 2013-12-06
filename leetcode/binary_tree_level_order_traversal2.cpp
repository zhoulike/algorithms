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