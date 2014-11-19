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
    TreeNode *sortedArrayToBST(vector<int> &num) {
        if (num.empty())
            return nullptr;
        else
            return createTree(num, 0, num.size() - 1);
    }
private:
    TreeNode* createTree(vector<int> &num, int low, int high) {
        if (low > high)
            return nullptr;
        int mid = low + (high - low) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = createTree(num, low, mid - 1);
        root->right = createTree(num, mid + 1, high);
    }
};
