class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board.size(); ++j) {
                if (board[i][j] != '.' && check(board, i, j) == false)
                    return false;
            }
        }
        return true;
    }
private:
    bool check(vector<vector<char> > &board, int i, int j)
    {
        size_t n = board.size();
        
        for (int k = 0; k < n; ++k) {  // check the same row
            if (k != j && board[i][k] == board[i][j])
                return false;
        }

        for (int k = 0; k < n; ++k) {  // check the same column
            if (k != i && board[k][j] == board[i][j])
                return false;
        }

        int box_i = i / 3, box_j = j / 3;
        for (int l = box_i * 3; l < box_i * 3 + 3; ++l) {  //check the same sub-box
            for (int m = box_j * 3; m < box_j * 3 + 3; ++m) {
                if (l != i && m != j && board[l][m] == board[i][j])
                    return false;
            }
        }

        return true;
    }
};
