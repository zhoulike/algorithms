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
    bool hasPathSum(TreeNode *root, int sum) {
        if (!root)
            return false;
        else if (root->val == sum && !root->left && !root->right)
            return true;
        else 
            return hasPathSum(root->left, sum - root->val) ||
                   hasPathSum(root->right, sum - root->val);
    }
};
