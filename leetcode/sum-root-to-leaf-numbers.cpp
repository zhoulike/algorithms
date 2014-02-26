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
    int sumNumbers(TreeNode *root) {
        if(!root)
            return 0;
        iterSum(root, root->val);
    }
private:
    int iterSum(TreeNode *node, int value){
        if(!node->left && !node->right)
            return value;
        else if(node->left && node->right)
            return iterSum(node->left, value * 10 + node->left->val) + iterSum(node->right, value * 10 + node->right->val);
        else if(node->left)
            return iterSum(node->left, value * 10 + node->left->val);
        else
            return iterSum(node->right, value * 10 + node->right->val);
    }
};