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
        return pathSumIter(root, sum, 0);
    }
private:
    bool pathSumIter(TreeNode *root, int sum, int temp_sum) {
        if(!root)
            return false;
        else if(!root->left && !root->right && root->val + temp_sum == sum)
            return true;
        else
            return pathSumIter(root->left, sum, root->val + temp_sum) || pathSumIter(root->right, sum, root->val + temp_sum);
    }
};