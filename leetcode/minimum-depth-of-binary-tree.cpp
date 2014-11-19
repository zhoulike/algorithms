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
    int minDepth(TreeNode *root) {
        if(root == NULL)
            return 0;
        
        int left = minDepth(root->left), right = minDepth(root->right);
        if(root->left && root->right)  //have two child, choose the minimum one
            return left < right? left + 1: right + 1;
        else if(!root->left && !root->right) //no child
            return 1;
        else  //only one child
            return left == 0? right + 1: left + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode *root) {
        if (!root)
            return 0;
        else if (!root->left && !root->right)
            return 1;
        else {
            int depth = INT_MAX;
            if (root->left)
                depth = 1 + minDepth(root->left);
            if (root->right)
                depth = min(depth, 1 + minDepth(root->right));
            return depth;
        }
    }
};
