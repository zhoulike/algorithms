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
    bool isBalanced(TreeNode *root) {
        if (!root)   //Note: an empty tree is a blanced tree
            return true;
        
        int left = depth(root->left), right = depth(root->right);
        return abs(left - right) <= 1 && isBalanced(root->left) && isBalanced(root->right);
    }
private:
    int depth(TreeNode *root) {
        if(root == NULL)
            return 0;
        return 1 + max(depth(root->left), depth(root->right));
    }
};

class Solution2 { //faster
public:
    bool isBalanced(TreeNode *root) {
        int tmp;
        return isBalanced(root, tmp);
    }
private:
    bool isBalanced(TreeNode* root, int& height) {
        if (!root) {
            height = 0;
            return true;
        }
        int left_height, right_height;
        auto left_balanced = isBalanced(root->left, left_height),
             right_balanced = isBalanced(root->right, right_height);
        height = 1 + max(left_height, right_height);
        return left_balanced && right_balanced && abs(left_height - right_height) <= 1;
    }
};
