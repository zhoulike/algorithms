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

//dp solution
class Solution {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n <= 0)
            return vector<TreeNode*>(1, nullptr);

        vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
        for (int i = 1; i <= n; ++i)
            dp[i][i].push_back(new TreeNode(i));
        for (int step = 2; step <= n; ++step) {
            for (int start = 1; start <= n - step + 1; ++start) {
                int end = start + step - 1;
                for (int i = start; i <= end; ++i) {
                    vector<TreeNode*> left, right;
                    if (i == start)
                        left.push_back(nullptr);
                    else
                        left = dp[start][i - 1];
                    if (i == end)
                        right.push_back(nullptr);
                    else
                        right = dp[i + 1][end];

                    for (auto leftSubtree: left) {
                        for (auto rightSubtree: right) {
                            dp[start][end].push_back(new TreeNode(i));
                            dp[start][end].back()->left = leftSubtree;
                            dp[start][end].back()->right = rightSubtree;
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};
