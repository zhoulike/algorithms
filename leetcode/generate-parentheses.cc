class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string curr;
        solve(ans, curr, n);
        return ans;
    }
    private:
    void solve(vector<string> &ans, string curr, int n) {
        if (n == 0) {
            ans.push_back(curr);
            return;
        }
        for (int i = 1; i <= n; ++i) {
            vector<string> left, right; //left part & right part
            solve(left, curr + "(", i - 1); //() inside i - 1 parentheses
            solve(right, "", n - i); //the remaining
            for (auto r: right) { //concatenate left part & right part
                for (auto l: left)
                    ans.push_back(string(l + ")" + r));
            }
        }
    }
};
