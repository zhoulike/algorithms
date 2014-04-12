class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        if (board.size() == 0 || word.size() == 0 ||
            board.size() * board[0].size() < word.size())
            return false;

        vector<vector<bool> > color(board.size(), vector<bool>(board[0].size(), false));

        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == word[0]) {
                    if (DFS(board, word, color, 0, i, j))
                        return true;
                }
            }
        }
        
        return false;
    }

private:
    bool DFS(vector<vector<char> > &board, string word, vector<vector<bool> > &color, int pos, int i, int j) {
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size()
            || color[i][j] == true
            || board[i][j] != word[pos])
            return false;

        if (pos == word.size() - 1)
            return true;

        color[i][j] = true;
        if (DFS(board, word, color,  pos + 1, i - 1, j)
            || DFS(board, word, color, pos + 1, i + 1, j)
            || DFS(board, word, color, pos + 1, i, j - 1)
            || DFS(board, word, color, pos + 1, i, j + 1))
            return true;
        
        color[i][j] = false;
        return false;
    }
};