class Solution {
public:
    int totalNQueens(int n) {
        vector<int> board(n);  //simulate 2d board
        int ans = 0;
        helper(board, 0, n, ans);
        return ans;
    }
private:
    void helper(vector<int> &board, int k, int n, int &ans) {
        if (k == n)
            ++ans;
        else {
            for (int i = 0; i < n; ++i) {
                board[k] = i;  //queen at (k, i)
                if (isValid(board, k))
                    helper(board, k + 1, n, ans);
            }
        }
    }

    bool isValid(vector<int> &board, int k) {
        for (int i = 0; i < k; ++i)
            if (board[i] == board[k] || abs(i - k) == abs(board[i] - board[k]))
                return false;
        return true;
    }
};
