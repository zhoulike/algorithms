//test case:
//XOOOOOOOOOOOOOOOOOOO
//OXOOOOXOOOOOOOOOOOXX
//OOOOOOOOXOOOOOOOOOOX
//OOXOOOOOOOOOOOOOOOXO
//OOOOOXOOOOXOOOOOXOOX
//XOOOXOOOOOXOXOXOXOXO
//OOOOXOOXOOOOOXOOXOOO
//XOOOXXXOXOOOOXXOXOOO
//OOOOOXXXXOOOOXOOXOOO
//XOOOOXOOOOOOXXOOXOOX
//OOOOOOOOOOXOOXOOOXOX
//OOOOXOXOOXXOOOOOXOOO
//XXOOOOOXOOOOOOOOOOOO
//OXOXOOOXOXOOOXOXOXOO
//OOXOOOOOOOXOOOOOXOXO
//XXOOOOOOOOXOXXOOOXOO
//OOXOOOOOOOXOOXOXOXOO
//OOOXOOOOOXXXOOXOOOXO
//OOOOOOOOOOOOOOOOOOOO
//XOOOOXOOOXXOOXOXOXOO

//Solution1: Time Limit Exceeded
//test case runtime: 0.9s
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[i].size(); ++j) {
                if (board[i][j] == 'O') {  //BFS
                    bool surrounded = true;
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    while (!q.empty()) {
                        auto pos = q.front();
                        q.pop();
                        int si = pos.first, sj = pos.second;
                        board[si][sj] = 'v';  //visited
                        if (si == 0 || si == board.size() - 1 ||
                            sj == 0 || sj == board[si].size() - 1)
                            surrounded = false;

                        //4 directions
                        if (si > 0 && board[si - 1][sj] == 'O')
                            q.push({si - 1, sj});
                        if (si < board.size() - 1 && board[si + 1][sj] == 'O')
                            q.push({si + 1, sj});
                        if (sj > 0 && board[si][sj - 1] == 'O')
                            q.push({si, sj - 1});
                        if (sj < board.size() - 1 && board[si][sj + 1] == 'O')
                            q.push({si, sj + 1});
                    }
                    if (surrounded)
                        fill(board, 'v', 's');  //surrounded
                    else
                        fill(board, 'v', 'n'); //not surrounded
                }
            }
        }
        fill(board, 's', 'X');
        fill(board, 'n', 'O');
    }
private:
    void fill(vector<vector<char>> &board, char old_val, char new_val)
    {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[0].size(); ++j)
                if (board[i][j] == old_val)
                    board[i][j] = new_val;
    }
};

//Optimized Solution2: Time Limit Exceeded
//test case runtime: 2.1s (WTF!!!)
//reduce unnecessary loop
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;

        for (int i = 0; i < board.size(); ++i) {
            if (board[i][0] == 'O')
                bfs(board, i, 0);
            if (board[i][board[i].size() - 1] == 'O')
                bfs(board, i, board[i].size() - 1);
        }
        for (int j = 0; j < board[0].size(); ++j) {
            if (board[0][j] == 'O')
                bfs(board, 0, j);
            if (board[board.size() - 1][j] == 'O')
                bfs(board, board.size() - 1, j);
        }

        fill(board, 'O', 'X');
        fill(board, 'V', 'O');
    }
private:
    void bfs(vector<vector<char>> &board, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int si = pos.first, sj = pos.second;
            board[si][sj] = 'V';  //visited

            //4 directions
            if (si > 0 && board[si - 1][sj] == 'O')
                q.push({si - 1, sj});
            if (si < board.size() - 1 && board[si + 1][sj] == 'O')
                q.push({si + 1, sj});
            if (sj > 0 && board[si][sj - 1] == 'O')
                q.push({si, sj - 1});
            if (sj < board[0].size() - 1 && board[si][sj + 1] == 'O')
                q.push({si, sj + 1});
        }
    }
    void fill(vector<vector<char>> &board, char old_val, char new_val)
    {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == old_val)
                    board[i][j] = new_val;
    }
};

//Optimized Solution3: Time Limit Exceeded
//test case runtime: 0.3s
//Improve cache hit rate. Note the importance of cache hot.
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;

        for (int i = 0; i < board.size(); ++i)
            if (board[i][0] == 'O')
                bfs(board, i, 0);

        for (int i = 0; i < board.size(); ++i)    //Difference Here!!!
            if (board[i][board[i].size() - 1] == 'O')
                bfs(board, i, board[i].size() - 1);

        for (int j = 0; j < board[0].size(); ++j)
            if (board[0][j] == 'O')
                bfs(board, 0, j);

        for (int j = 0; j < board[0].size(); ++j)   //Difference Here!!!
            if (board[board.size() - 1][j] == 'O')
                bfs(board, board.size() - 1, j);

        fill(board, 'O', 'X');
        fill(board, 'V', 'O');
    }
private:
    void bfs(vector<vector<char>> &board, int i, int j)
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int si = pos.first, sj = pos.second;
            board[si][sj] = 'V';  //visited

            //4 directions
            if (si > 0 && board[si - 1][sj] == 'O')
                q.push({si - 1, sj});
            if (si < board.size() - 1 && board[si + 1][sj] == 'O')
                q.push({si + 1, sj});
            if (sj > 0 && board[si][sj - 1] == 'O')
                q.push({si, sj - 1});
            if (sj < board[0].size() - 1 && board[si][sj + 1] == 'O')
                q.push({si, sj + 1});
        }
    }
    void fill(vector<vector<char>> &board, char old_val, char new_val)
    {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == old_val)
                    board[i][j] = new_val;
    }
};


//Optimized Solution4: Accept (56ms)
//test case runtime: 0s
//Modify BFS!
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        if (board.size() == 0 || board[0].size() == 0)
            return;

        for (int i = 0; i < board.size(); ++i)
            if (board[i][0] == 'O')
                bfs(board, i, 0);

        for (int i = 0; i < board.size(); ++i) 
            if (board[i][board[i].size() - 1] == 'O')
                bfs(board, i, board[i].size() - 1);
                
        for (int j = 0; j < board[0].size(); ++j) 
            if (board[0][j] == 'O')
                bfs(board, 0, j);

        for (int j = 0; j < board[0].size(); ++j)
            if (board[board.size() - 1][j] == 'O')
                bfs(board, board.size() - 1, j);

        fill(board, 'O', 'X');
        fill(board, 'V', 'O');
    }
private:
    void bfs(vector<vector<char>> &board, int i, int j)   //Difference Here!
    {
        queue<pair<int, int>> q;
        q.push({i, j});
        board[i][j] = 'V';  //visited
        while (!q.empty()) {
            auto pos = q.front();
            q.pop();
            int si = pos.first, sj = pos.second;

            //4 directions
            if (si > 0 && board[si - 1][sj] == 'O') {
                board[si - 1][sj] = 'V';  //marked as visited when enqueue, avoid multiple enqueue.
                q.push({si - 1, sj});
            }
            if (si < board.size() - 1 && board[si + 1][sj] == 'O') {
                board[si + 1][sj] = 'V';
                q.push({si + 1, sj});
            }
            if (sj > 0 && board[si][sj - 1] == 'O') {
                board[si][sj - 1] = 'V';
                q.push({si, sj - 1});
            }
            if (sj < board[0].size() - 1 && board[si][sj + 1] == 'O') {
                board[si][sj + 1] = 'V';
                q.push({si, sj + 1});
            }
        }
    }
    void fill(vector<vector<char>> &board, char old_val, char new_val)
    {
        for (int i = 0; i < board.size(); ++i)
            for (int j = 0; j < board[i].size(); ++j)
                if (board[i][j] == old_val)
                    board[i][j] = new_val;
    }
};
