class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        helper(s, 0, ans, curr);
        return ans;
    }
private:
    void helper(string& s, int start, vector<vector<string>>& ans, vector<string>& curr) {
        if (start == s.size()) {
            ans.push_back(curr);
            return;
        }

        for (int i = start + 1; i <= s.size(); ++i) {  //i < s.size() is wrong. Think about [first, last).
            if (isPalindrome(s.begin() + start, s.begin() + i)) {
                curr.push_back(string(s.begin() + start, s.begin() + i));
                helper(s, i, ans, curr);
                curr.pop_back();
            }
        }
    }
    bool isPalindrome(string::iterator first, string::iterator last) {
        --last;
        while (first < last && *first == *last) {
            ++first;
            --last;
        }
        return first >= last;
    }
};
