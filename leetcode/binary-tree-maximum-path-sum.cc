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
    int maxPathSum(TreeNode *root) {
        int tmp;
        return helper(root, tmp);
    }
private:
    int helper(TreeNode *root, int &half) {  //return the maximum path sum of a tree
        if (!root) {
            half = INT_MIN;
            return half;
        } 
        
        int left_half, right_half, curr_path;  //curr_path: the maximum path sum of this tree
        int left_max_path = helper(root->left, left_half),
            right_max_path = helper(root->right, right_half);  
        //the maximum path sum of left and right sub-tree
        
        if (left_half > 0 && right_half > 0) {
            half = root->val + (left_half > right_half? left_half: right_half);
            curr_path = left_half + right_half + root->val;
        } else if (left_half > 0)
            curr_path = half = root->val + left_half;
        else if (right_half > 0)
            curr_path = half = root->val + right_half;
        else
            curr_path = half = root->val;
        
        return left_max_path > right_max_path? max(left_max_path, curr_path): max(right_max_path, curr_path);
    }
};

//simple algorithm, cleaner code
class Solution {
public:
    int maxPathSum(TreeNode *root) {
        if (!root)
            return 0;
        maxSubtreeSum(root);
        return max_sum;
    }
private:
    int maxSubtreeSum(TreeNode *root) {
        if (!root)
            return 0;
        int left_path = maxSubtreeSum(root->left),
            right_path = maxSubtreeSum(root->right);

        int ret = max3(left_path + root->val, right_path + root->val, root->val);
        max_sum = max3(max_sum, left_path + right_path + root->val, ret);
        return ret;
    }
    int max3(int i1, int i2, int i3) {
        return max(max(i1, i2), i3);
    }

    int max_sum = INT_MIN;
};
