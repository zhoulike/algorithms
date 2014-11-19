//DP
class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string> &dict) {
        vector<bool> matched(s.size() + 1, false);   //matched[i] ==> s[0, i) can be broken
        matched[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (matched[j] == true && dict.find(s.substr(j, i - j)) != dict.end())
                    matched[i] = true;
            }
        }

        vector<string> ans;
        if (!matched.back())   //s cannot be broken
            return ans;
        helper(s, dict, "", 0, ans);

        return ans;
    }
private:
    void helper(string &s, unordered_set<string> &dict, 
                string curr, int start, vector<string> &ans) {
        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }
        for (int i = start; i < s.size(); ++i) {
            string sub = s.substr(start, i - start + 1);
            if (dict.find(sub) != dict.end()) {
                string tmp = curr.empty()? sub: curr + " " + sub;
                helper(s, dict, tmp, i + 1, ans);
            }
        }
    }
};
