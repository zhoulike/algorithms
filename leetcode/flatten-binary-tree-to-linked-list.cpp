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
    void flatten(TreeNode *root) {
        if (!root)
            return;
        
        if (root->left) {
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;  //don't forget this sentence
        
            if (right) {
                TreeNode *tmp = root->right;   //previous root->left
                while (tmp->right)
                    tmp = tmp->right;
                    
                tmp->right = right;
            }
        }
        
        flatten(root->right);
    }
};