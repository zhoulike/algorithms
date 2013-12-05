/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [3,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode *root) {
        vector<int> ivec;
        stack<pair<TreeNode*, bool> > s;
        if(root)
            s.push(make_pair(root, false));
            
        while(!s.empty()){
            TreeNode* tmp = s.top().first;
            bool visited = s.top().second;
            s.pop();
            
            if(visited || !tmp->left && !tmp->right)
                ivec.push_back(tmp->val);
            else {
                s.push(make_pair(tmp, true));
                if(tmp->right)
                    s.push(make_pair(tmp->right, false));
                if(tmp->left)
                    s.push(make_pair(tmp->left, false));
            }
        }
        
        return ivec;
    }