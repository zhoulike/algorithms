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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<int> path;
        pathSum(root, sum, path);
        return ans;
    }
private:
    vector<vector<int>> ans;
    void pathSum(TreeNode *root, int sum, vector<int> &path) {
        if (!root)
            return;
        path.push_back(root->val);
        if (!root->left && !root->right && sum == root->val)
            ans.push_back(path);
        else {
            pathSum(root->left, sum - root->val, path);
            pathSum(root->right, sum - root->val, path);
        }
        path.pop_back();
    }
};
