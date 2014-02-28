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
    bool isSymmetric(TreeNode *root) {
        if(!root)
            return true;
        
        return childSymmetric(root->left, root->right);
    }
private:
    bool childSymmetric(TreeNode *first, TreeNode* last) {
        if (!first && !last)
            return true;
        else if (!first || !last || first->val != last->val)
            return false;
        else
            return childSymmetric(first->left, last->right) && childSymmetric(first->right, last->left);
    }
};