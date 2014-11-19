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
        vector<int> ans;
        stack<TreeNode*> stk;
        if (root)
            stk.push(root);

        while (!stk.empty()) {
            auto curr = stk.top();
            stk.pop();
            ans.push_back(curr->val);
            if (curr->right)
                stk.push(curr->right);
            if (curr->left)
                stk.push(curr->left);
        }
        return ans;
    }
};
