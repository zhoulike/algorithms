class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
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
        
        for (int i = start; i < s.size();) {
            curr.push_back(s[i]);  //use once
            subsetsBt(ans, curr, s, ++i);
            curr.pop_back();
            
            while (i > 0 && i < s.size() && s[i] == s[i - 1])  //and skip duplicated items
                ++i;
        }
    }
};