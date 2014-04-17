class Solution {
public:
    vector<vector<int> > combine(int n, int k) {
        vector<vector<int> > ans;
        if (n <= 0 || k <= 0 || n < k)
            return ans;

        vector<int> curr;
        combineBt(ans, curr, n, 1, k);
        return ans;
    }
private:
    void combineBt(vector<vector<int> > &ans, vector<int> curr, int n, int start, int k) {
        if (k == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i <= n; ++i) {
            curr.push_back(i);
            combineBt(ans, curr, n, i + 1, k - 1);
            curr.pop_back();
        }
    }
};