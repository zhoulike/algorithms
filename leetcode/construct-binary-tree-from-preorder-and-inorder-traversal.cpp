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
    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        return build_iter(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
    }
private:
    TreeNode *build_iter(vector<int>::iterator first1, vector<int>::iterator last1, vector<int>::iterator first2, vector<int>::iterator last2) {
        if (first1 == last1 || first2 == last2)
            return NULL;
            
        TreeNode *p = new TreeNode(*first1);
        vector<int>::iterator mid2 = find(first2, last2, *first1);
        vector<int>::iterator mid1 = first1 + 1 + (mid2 - first2);
        p->left = build_iter(first1 + 1, mid1, first2, mid2);
        p->right = build_iter(mid1, last1, mid2 + 1, last2);
        
        return p;
    }
};