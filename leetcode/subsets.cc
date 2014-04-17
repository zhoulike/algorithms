class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        vector<vector<int> > ans;
        vector<int> curr;
        sort(S.begin(), S.end());  //guarantee each subset in ascending order
        subsetsBt(ans, curr, S, 0);
        
        return ans;
    }
private:
    void subsetsBt(vector<vector<int> > &ans, vector<int> &curr, vector<int> &s, int start)
    {
        ans.push_back(curr);
        for (int i = start; i < s.size(); ++i) {
            curr.push_back(s[i]);
            subsetsBt(ans, curr, s, i + 1);
            curr.pop_back();
        }
    }
};