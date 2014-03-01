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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        return build_iter(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
    }
private:
    TreeNode *build_iter(vector<int>::iterator first1, vector<int>::iterator last1, vector<int>::iterator first2, vector<int>::iterator last2) {
        if (first1 == last1 || first2 == last2)
            return NULL;
            
        TreeNode *p = new TreeNode(*(last2 - 1));
        vector<int>::iterator mid1 = find(first1, last1, *(last2 - 1));
        vector<int>::iterator mid2 = first2 + (mid1 - first1);
        p->left = build_iter(first1, mid1, first2, mid2);
        p->right = build_iter(mid1 + 1, last1, mid2, last2 - 1);
        
        return p;
    }
};