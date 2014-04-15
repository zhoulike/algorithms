class Solution {
public:
    vector<vector<string> > solveNQueens(int n) { //backtrace solution
        string s = string(n, '.');
        vector<string> vs(n, s);
        vector<vector<string> > ans;
        nQueue_bt(ans, vs, 0, n);
        return ans;
    }
private:
    void nQueue_bt(vector<vector<string> > &ans, vector<string> &vs, int line, int n) {
        if (line >= n)
            return;

        for (int j = 0; j < n; ++j) {
            vs[line][j] = 'Q';
            if (isValid(vs, line, j, n)) {
                if (line == n - 1)
                    ans.push_back(vs);
                else
                    nQueue_bt(ans, vs, line + 1, n);
            }
            vs[line][j] = '.';
        }
    }

    bool isValid(const vector<string> &vs, int i, int j, int n) {
        for (int l = 0; l < i; ++l) {  //check the same column
            if (vs[l][j] == 'Q')
                return false;
        }
        
        for (int l = i - 1, m = j - 1; l >= 0 && m >= 0; --l, --m) {  //check left diagonal
            if (vs[l][m] == 'Q')
                return false;
        }

        for (int l = i - 1, m = j + 1; l >= 0 && m < n; --l, ++m) { //check right diagonal
            if (vs[l][m] == 'Q')
                return false;
        }

        return true;
    }
};
