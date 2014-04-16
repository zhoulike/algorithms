class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        if (board.size() != 9)
            return;

        solved = false;
        solveSudokuBt(board, 0, 0);
    }
private:
    void solveSudokuBt(vector<vector<char> > &board, int i , int j)
    {
        size_t n = board.size();
        if (solved || i == n) {
            solved = true;
            return;
        }

        int next_i = i, next_j = j + 1;
        if (next_j == n) {
            ++next_i;
            next_j = 0;
        }

        if (board[i][j] == '.') {
            for (char v = '1'; v <= '9'; ++v) {
                board[i][j] = v;
                if (check(board, i, j))
                    solveSudokuBt(board, next_i, next_j);
                if (solved)
                    return;
            }
            board[i][j] = '.';
        } else
            solveSudokuBt(board, next_i, next_j);
    }

    bool check(vector<vector<char> > &board, int i, int j)
    {
        size_t n = board.size();

        for (int k = 0; k < n; ++k) { //check the same row
            if (k != j && board[i][k] == board[i][j])
                return false;
        }

        for (int k = 0; k < n; ++k) { //check the same column
            if (k != i && board[k][j] == board[i][j])
                return false;
        }

        int box_i = i / 3, box_j = j / 3; //check the same sub-box
        for (int l = box_i * 3; l < box_i * 3 + 3; ++l) {
            for (int m = box_j * 3; m < box_j * 3 + 3; ++m) {
                if (l != i && m != j && board[l][m] == board[i][j])
                    return false;
            }
        }

        return true;
    }
    
    bool solved;
};