class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.size() == 0)
            return string("");
        
        int shortest = strs[0].size();
        for(int i = 1; i < strs.size(); ++i)
            if(strs[i].size() < shortest)
                shortest = strs[i].size();
        
        string prefix;
        for(int j = 0; j < shortest; ++j) {
            prefix.push_back(strs[0][j]);
            for(int i = 1; i < strs.size(); ++i) {
                if(strs[i][j] != prefix[j]) {
                    prefix.pop_back();
                    break;
                }
            }
        }
        
        return prefix;
    }
};