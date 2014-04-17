class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string curr;
        combinationBt(ans, curr, digits, 0, digits.size());
        return ans;
    }

    Solution() {
        phone = {
            {'1', ""},
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
    }
private:
    void combinationBt(vector<string> &ans, string &curr, string digits, int start, int remain)
    {
        if (remain == 0) {
            ans.push_back(curr);
            return;
        }

        for (auto ch: phone[digits[start]]) {
            curr.push_back(ch);
            combinationBt(ans, curr, digits, start + 1, remain - 1);
            curr.pop_back();
            //curr.erase(curr.end() - 1);
        }
    }
    map<char, string> phone;
};