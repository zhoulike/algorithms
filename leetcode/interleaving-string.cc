//recursion: Time Limit Exceeded
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        return solve(s1, 0, s2, 0, s3, 0);
    }
private:
    bool solve(string& s1, int beg1, string& s2, int beg2, string& s3, int beg3)
    {
        if (beg1 == s1.size())
            return string(s2.begin() + beg2, s2.end()) == string(s3.begin() + beg3, s3.end());

        if (beg2 == s2.size())
            return string(s1.begin() + beg1, s1.end()) == string(s3.begin() + beg3, s3.end());

        bool ans = false;
        if (s1[beg1] == s3[beg3]) {
            ans = solve(s1, beg1 + 1, s2, beg2, s3, beg3 + 1);
            if (ans == true)
                return ans;
        }
        if (s2[beg2] == s3[beg3])
            ans |= solve(s1, beg1, s2, beg2 + 1, s3, beg3 + 1);
        return ans;
    }
};

//DP: Runtime 8ms
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;

        //v[i][j] = k, we need test s1[i] == s3[k] or s2[j] == s3[k]
        vector<vector<int>> v(s1.size() + 1, vector<int>(s2.size() + 1, -1));
        v[0][0] = 0;
        for (int i = 0; i < v.size(); ++i) {
            for (int j = 0; j < v[0].size(); ++j) {
                if (v[i][j] != -1) {
                    int k = v[i][j];
                    if (s1[i] == s3[k] && i + 1 < v.size() && k + 1 > v[i + 1][j])
                        v[i + 1][j] = k + 1;
                    if (s2[j] == s3[k] && j + 1 < v[0].size() && k + 1 > v[i][j + 1])
                        v[i][j + 1] = k + 1;
                }
            }
        }

        return v.back().back() == s3.size();
    }
};
