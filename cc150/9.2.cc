#include <iostream>
#include <vector>

using namespace std;

int robot_paths(int x, int y)
{
    if (x < 0 || y < 0)
        return 0;

    vector<vector<int> > paths(x + 1, vector<int>(y + 1));
    paths[0][0] = 1;

    for (int i = 0; i < paths.size(); ++i) {
        for (int j = 0; j < paths[0].size(); ++j) {
            if (j - 1 >= 0)
                paths[i][j] += paths[i][j - 1];
            if (i - 1 >= 0)
                paths[i][j] += paths[i - 1][j];
        }
    }

    return paths[x][y];
}

enum {SOURCE, UP, LEFT};

void print(vector<vector<int> > &path, int i, int j)
{
    if (path[i][j] == UP)
        print(path, i - 1, j);
    else if (path[i][j] == LEFT)
        print(path, i, j - 1);

    cout << i << ", " << j << endl;
}

void robot_path_spots(vector<vector<int> >& board)
{
    if (board.size() == 0 || board[0].size() == 0)
        return;

    vector<vector<int> > path(board.size(), vector<int>(board[0].size(), -1));
    path[0][0] = SOURCE;
    
    for (int i = 0; i < path.size(); ++i) {
        for (int j = 0; j < path[i].size(); ++j) {
            if (board[i][j] == 1)
                continue;
            if (j - 1 >= 0 && path[i][j - 1] != -1)
                path[i][j] = LEFT;
            if (i - 1 >= 0 && path[i - 1][j] != -1)
                path[i][j] = UP;
        }
    }

    if (path.back().back() == -1)
        cout << "no path!" << endl;
    else
        print(path, path.size() - 1, path[0].size() - 1);
}

void test(int x, int y)
{
    cout << "(0, 0) -> (" << x << ", " << y << "), paths: " 
         << robot_paths(x, y) << endl;
}

int main(int argc, char *argv[])
{
    test(0, 0);
    test(1, 1);
    test(2, 2);
    test(3, 4);

    vector<vector<int> > v = {
        {0, 0, 0, 1},
        {0, 1, 1, 1},
        {0, 0, 0, 0}
    };

    robot_path_spots(v);
    return 0;
}
