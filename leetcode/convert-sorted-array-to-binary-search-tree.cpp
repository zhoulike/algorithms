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
        return child(num.begin(), num.end());
    }
    
private:
    TreeNode *child(vector<int>::iterator first, vector<int>::iterator last)
    {
        if (first >= last)
            return NULL;
        
        vector<int>::iterator mid = first + (last - first) / 2;
        TreeNode *p = new TreeNode(*mid);
            
        p->left = child(first, mid);  //note: [first, last)
        p->right = child(mid + 1, last);
        
        return p;
    }
};