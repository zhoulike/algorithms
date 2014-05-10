/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

//stupid solution: O(n) time, O(n) space
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        vector<int> ivec;
        inorder(root, ivec);
        for (int i = 1; i < ivec.size(); ++i) {
            if (ivec[i] <= ivec[i - 1])
                return false;
        }
        return true;
    }
private:
    void inorder(TreeNode* root, vector<int>& ivec)
    {
        if (root) {
            inorder(root->left, ivec);
            ivec.push_back(root->val);
            inorder(root->right, ivec);
        }
    }
};

//bottom-up solution: O(n) time, O(1) space
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        int child_min = INT_MAX, child_max = INT_MIN;
        return solve(root, child_min, child_max);
    }
private:
    bool solve(TreeNode *root, int &child_min, int &child_max) {
        if (!root) {
            child_min = INT_MAX;
            child_max = INT_MIN;
            return true;
        }
        
        int left_min, left_max;
        if (solve(root->left, left_min, left_max) == false || root->val <= left_max)
            return false;
        child_min = min(root->val, left_min);
        
        int right_min, right_max;
        if (solve(root->right, right_min, right_max) == false || root->val >= right_min)
            return false;
        child_max = max(root->val, right_max);
        
        return true;
    }
};

//top-down solution: O(n) time, O(1) space
//simpler and better!!
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        return solve(root, INT_MIN, INT_MAX);
    }
private:
    bool solve(TreeNode *root, int min_val, int max_val) {
        if (!root)
            return true;
        else if (root->val < min_val || root->val > max_val)
            return false;
        else
            return solve(root->left, min_val, root->val - 1) &&
                   solve(root->right, root->val + 1, max_val);

    }
};
