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
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        int left = minDepth(root->left), right = minDepth(root->right);
        if(root->left && root->right)  //have two child, choose the minimum one
            return left < right? left + 1: right + 1;
        else if(!root->left && !root->right) //no child
            return 1;
        else  //only one child
            return left == 0? right + 1: left + 1;
    }
};