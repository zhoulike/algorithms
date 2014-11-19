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
    bool isSymmetric(TreeNode *root) {
        if (!root)
            return true;
        return isSymmetric(root->left, root->right);
    }
private:
    bool isSymmetric(TreeNode *first, TreeNode *second) {
        if (!first && !second)
            return true;
        else if (first && second && first->val == second->val)
            return isSymmetric(first->left, second->right) && 
                   isSymmetric(first->right, second->left);
        else
            return false;
    }
};

class Solution2 {
public:
    bool isSymmetric(TreeNode *root) {
        queue<TreeNode*> q;
        if (root) {
            q.push(root->left);
            q.push(root->right);
        }
        while (!q.empty()) {
            auto first = q.front();
            q.pop();
            auto second = q.front();
            q.pop();
            if (!first && !second)
                continue;
            else if (first && second && first->val == second->val) {
                q.push(first->left);
                q.push(second->right);
                q.push(first->right);
                q.push(second->left);
            } else
                return false;
        }
        return true;
    }
};
