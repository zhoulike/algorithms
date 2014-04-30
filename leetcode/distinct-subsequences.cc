//recursive solution: Time Limit Exceeded
class Solution {
public:
    int numDistinct(string S, string T) {
        return helper(S, 0, T, 0);
    }
private:
    int helper(string& S, int start_S, string& T, int start_T) {
        if (start_T == T.size()) //find one match
            return 1;
        else if (S.size() - start_S < T.size() - start_T) //the remaining of S is too short
            return 0;

        //S[i] == T[j]:
        //1) check S[i+1 ...] and T[j+1 ...]
        //2) check S[i+1 ...] and T[j ...]
        //exmaple: S = ACACE, T = ACE. S[0] = T[0].
        if (S[start_S] == T[start_T])
            return helper(S, start_S + 1, T, start_T + 1) +
                   helper(S, start_S + 1, T, start_T);
        else //check S[i+1 ...] and T[j ...]
            return helper(S, start_S + 1, T, start_T);
    }
};

//DP solution: the computation is reverse.
class Solution {
public:
    int numDistinct(string S, string T) { 
        vector<vector<int> > ans(S.size() + 1, vector<int>(T.size() + 1, 0));
        for (int i = 0; i < S.size() + 1; ++i) // empty T is a subsequence of any S
            ans[i][0] = 1;

        //if ... else ... is the reverse of recursive solution
        for (int i = 1; i < S.size() + 1; ++i) {
            for (int j = 1; j < T.size() + 1; ++j) {
                if (S[i - 1] == T[j - 1]) {
                    ans[i][j] = ans[i - 1][j - 1] + ans[i - 1][j];
                }
                else
                    ans[i][j] = ans[i - 1][j];
            }
        }

        return ans.back().back();
    }
};
