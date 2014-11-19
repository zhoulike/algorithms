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
    void flatten(TreeNode *root) {
        if (!root)
            return;
        
        if (root->left) {
            TreeNode *right = root->right;
            root->right = root->left;
            root->left = NULL;  //don't forget this sentence
        
            if (right) {
                TreeNode *tmp = root->right;   //previous root->left
                while (tmp->right)
                    tmp = tmp->right;
                    
                tmp->right = right;
            }
        }
        
        flatten(root->right);
    }
};

class Solution {
public:
    void flatten(TreeNode *root) {
        TreeNode *tmp1, *tmp2;
        if (root)
            flatten(root, tmp1, tmp2);
    }
private:
    void flatten(TreeNode* root, TreeNode* &leftmost, TreeNode* &rightmost) {
        leftmost = rightmost = root;
        if (root->left || root->right) {
            TreeNode *leftmost_l, *leftmost_r, *rightmost_l, *rightmost_r;
            TreeNode *right = root->right;

            if (root->left) {
                flatten(root->left, leftmost_l, rightmost_l);
                rightmost->right = leftmost_l;
                rightmost = rightmost_l;
                root->left = nullptr; //don't forget to clear left pointer
            }
            if (right) {
                flatten(right, leftmost_r, rightmost_r);
                rightmost->right = leftmost_r;
                rightmost = rightmost_r;
            }
        }
    }
};
