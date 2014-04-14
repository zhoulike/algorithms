/*
s = "ABCDEFGHIJKLM"
->
A  G  M
B FH L
CE IK
D  J

diff = 6 (i.e. G-A = 6)
Row 1:
step = 6, diff-step = 0. (s[0], s[6], s[12]  -> AGM)
Row 2:
step = 4, diff-step = 2. (s[1], s[5], s[7], s[11] -> BFHL)
Row 3:
step = 2, diff-step = 4. (s[2], s[4], s[8], s[10] -> CEIK)
Row 4:
step = 0, diff-step = 6. (s[3], s[9] -> DJ)
*/

class Solution {
public:
    string convert(string s, int nRows) {
        if (nRows == 1 || nRows >= s.size())
            return s; 

        string ans;
        int diff, step;
        diff = step = 2 * (nRows - 1);
        
        for (int i = 0; i < nRows; ++i) {
            int j = i;
            ans += s[j];

            while (j < s.size()) {
                j += step;
                if (step > 0 && j < s.size())
                    ans += s[j];

                j += diff - step;
                if (diff - step > 0 && j < s.size())
                    ans += s[j];
            }

            step -= 2;
        }

        return ans;
    }
};