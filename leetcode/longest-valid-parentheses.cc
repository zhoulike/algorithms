class Solution {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1)
            return 0;

        vector<int> v(s.size(), 0);
        int longest = 0;
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] == ')') {
                if(s[i - 1] == '(') {  // e.g. ()
                    v[i] = 2;
                    if(i - 2 >= 0 && v[i - 2] != 0) // e.g. ()()
                        v[i] += v[i - 2];
                }
                else if(v[i - 1] != 0 && i - 1 - v[i - 1] >= 0 && s[i - 1 - v[i - 1]] == '(') { //e.g. (())
                    v[i] = v[i - 1] + 2;
                    if(i - 2 - v[i - 1] >= 0 && v[i - 2 - v[i - 1]] != 0) //e.g. ()(())
                        v[i] += v[i - 2 - v[i - 1]];
                }
            }
            longest = max(longest, v[i]);
        }

        return longest;
    }
};
