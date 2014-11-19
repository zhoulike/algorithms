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

//bottom-up solution: O(n) time, O(h) space
class Solution {
public:
    bool isValidBST(TreeNode *root) {
        if (!root)
            return true;
        int tmp1, tmp2;
        return isValidBST(root, tmp1, tmp2);
    }
private:
    bool isValidBST(TreeNode *root, int &lower_bound, int &upper_bound) {
        lower_bound = upper_bound = root->val;
        if (!root->left && !root->right)
            return true;
        if (root->left) {
            int left_lower, left_upper;
            bool isLeftValid = isValidBST(root->left, left_lower, left_upper);
            if (!isLeftValid || root->val <= left_upper)
                return false;
            lower_bound = left_lower;
            upper_bound = root->val;
        }
        if (root->right) {
            int right_lower, right_upper;
            bool isRightValid = isValidBST(root->right, right_lower, right_upper);
            if (!isRightValid || right_lower <= upper_bound)
                return false;
            upper_bound = right_upper;
        }
        return true;
    }
};

//top-down solution: O(n) time, O(h) space
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
        //corner case: {INT_MIN, INT_MIN}
        else if (root->val == INT_MAX && max_val == INT_MAX && root->right ||
                root->val == INT_MIN && min_val == INT_MIN && root->left)
            return false;
        else if (root->val < min_val || root->val > max_val)
            return false;
        else
            return solve(root->left, min_val, root->val - 1) &&
                solve(root->right, root->val + 1, max_val);

    }
};
