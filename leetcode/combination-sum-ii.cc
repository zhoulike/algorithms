class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int> &candidates, int target) {
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

        for (int i = start; i < candidates.size() && candidates[i] <= remain;) {
            curr.push_back(candidates[i]);  //use once
            solve(ans, candidates, curr, ++i, remain - candidates[i]);
            curr.pop_back();

            while (i > 0 && i < candidates.size() && candidates[i] == candidates[i - 1])
                ++i;  //and skip duplicated elements
        }
    }
};
