class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int> > ans;
        vector<int> curr;
        solve(ans, candidates, curr, 0, target);
        return ans;
    }
private:
    void solve(vector<vector<int> > &ans, vector<int> &candidates, vector<int> &curr, int start, int remain){
        if (remain == 0) {
            ans.push_back(curr);
            return;
        }

        for (int i = start; i < candidates.size() && candidates[i] <= remain; ++i) {
            curr.push_back(candidates[i]);
            solve(ans, candidates, curr, i, remain - candidates[i]);
            curr.pop_back();
        }
    }
};
