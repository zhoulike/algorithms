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
    vector<TreeNode *> generateTrees(int n) {
        return helper(1, n);
    }
private:
    vector<TreeNode *> helper(int start, int end)
    {
        vector<TreeNode *> ans;
        if (start > end)
            ans.push_back(NULL);

        for (int i = start; i <= end; ++i) {
            auto left = helper(start, i - 1);  //left has at least 1 element: NULL
            auto right = helper(i + 1, end);   //the same to right

            //Then, these loops do not need to check whether left and right are empty.
            for (auto p_left: left) {
                for (auto p_right: right) {
                    ans.push_back(new TreeNode(i));
                    ans.back()->left = p_left;
                    ans.back()->right = p_right;
                }
            }
        }
        
        return ans;
    }
};
