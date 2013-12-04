/*
Given a binary tree, return the preorder traversal of its nodes' values.

For example:
Given binary tree {1,#,2,3},
   1
    \
     2
    /
   3
return [1,2,3].

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
#include <stack>
#include <vector>

class Solution {
public:
    vector<int> preorderTraversal(TreeNode *root) {
        std::stack<TreeNode*> s;
        std::vector<int> ivec;
        
        if(root)
            s.push(root);
        
        while(!s.empty()){
            TreeNode *node = s.top();
            s.pop();
            ivec.push_back(node->val);
            
            if(node->right)
                s.push(node->right);
            if(node->left)
                s.push(node->left);
        }
        
        return ivec;
    }
};