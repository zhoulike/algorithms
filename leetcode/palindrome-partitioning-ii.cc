class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if (len <= 1)
            return 0;

        vector<vector<bool>> vec(len, vector<bool>(len, false));
        for (int i = 0; i < len; ++i)
            vec[i][i] = true;
        for (int i = 0; i < len - 1; ++i) {
            if (s[i] == s[i + 1])
                vec[i][i + 1] = true;
        }

        for (int chars = 3; chars <= len; ++chars) { //length of substr
            for (int i = 0; i <= len - chars; ++i) {
                int j = i + chars - 1;  //substr = s[i...j], including s[j]
                if (s[i] == s[j] && vec[i + 1][j - 1])
                    vec[i][j] = true;
            }
        }

        vector<int> cut(len + 1, INT_MAX);
        cut[0] = -1;  //sentinel: -1 + 1 = 0
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (vec[i][j])
                    cut[j + 1] = min(cut[j + 1], cut[i] + 1);
            }
        }
        return cut.back();
    }
};
