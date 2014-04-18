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
        vector<vector<int> > ans;
        if (!root)
            return ans;
            
        vector<int> path;
        pathSumRecur(root, sum, ans, path);
        return ans;
    }
private:
    void pathSumRecur(TreeNode *root, int remain, vector<vector<int> > &ans, vector<int> &path) {
        path.push_back(root->val);
        remain -= root->val;
        
        if (!root->left && !root->right && remain == 0)
            ans.push_back(path);
        else {
            if (root->left)
                pathSumRecur(root->left, remain, ans, path);
            if (root->right)
                pathSumRecur(root->right, remain, ans, path);
        }
            
        path.pop_back();
    }
};