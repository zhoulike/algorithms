//recursion: Time Limit Exceeded
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.find(s) != dict.end())
            return true;

        bool ans = false;
            
        for(auto iter = s.begin(); iter != s.end(); ++iter){
            if(dict.find(string(s.begin(), iter + 1)) != dict.end()) {
                ans = wordBreak(string(iter + 1, s.end()), dict);
                if (ans)
                    return ans;
            }
        }
        
        return false;
    }
};

//DP
class Solution {
public:
    bool wordBreak(string s, unordered_set<string> &dict) {
        if(dict.find(s) != dict.end())
            return true;

        vector<bool> matched(s.size() + 1, false);   //matched[i] ==> s[0, i) can be broken
        matched[0] = true;
        for (int i = 1; i <= s.size(); ++i) {
            for (int j = i - 1; j >= 0; --j) {
                if (matched[j] == true && dict.find(s.substr(j, i - j)) != dict.end())
                    matched[i] = true;
            }
        }
        return matched.back();
    }
};
