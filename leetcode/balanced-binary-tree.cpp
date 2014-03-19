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
    bool isBalanced(TreeNode *root) {
        if (!root)   //Note: an empty tree is a blanced tree
            return true;
        
        int left = maxDepth(root->left),
            right = maxDepth(root->right);
        
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int maxDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        int left = maxDepth(root->left),
            right = maxDepth(root->right);
        return left > right? (left + 1): (right + 1);
    }
};