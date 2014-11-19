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
        return sumNumbers(root, 0);
    }
private:
    int sumNumbers(TreeNode *root, int parent) {
        if (!root)
            return 0;
        else if (!root->left && !root->right)
            return parent * 10 + root->val;
        else
            return sumNumbers(root->left, parent * 10 + root->val) +
                sumNumbers(root->right, parent* 10 + root->val);
    }
};
