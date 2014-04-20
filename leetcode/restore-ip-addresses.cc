class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        string curr;
        solve(ans, curr, s, 0, 4);
        return ans;
    }
private:
    void solve(vector<string> &ans, string &curr, string s, int start, int remain)
    {
        int size = s.size();
        if (size - start > remain * 3)
            return;

        if (remain == 0) {
            ans.push_back(curr);
            ans.back().pop_back();
            return;
        }

        for (int i = start; i < min(start + 3, size); ++i) {
            if (i != start && s[start] == '0')
                break;
                
            string tmp(s.begin() + start, s.begin() + i + 1);
            int tmp_value = atoi(tmp.c_str());

            if (tmp_value >= 0 && tmp_value <= 255) {
                curr += tmp + ".";
                solve(ans, curr, s, i + 1, remain - 1);
                curr.erase(curr.end() - tmp.size() - 1, curr.end());
            }
        }
    }
};
