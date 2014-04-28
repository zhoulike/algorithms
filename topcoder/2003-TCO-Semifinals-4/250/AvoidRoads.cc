
// {{{ Boilerplate Code <--------------------------------------------------
// vim:filetype=cpp:foldmethod=marker:foldmarker={{{,}}}

#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define FOR(I,A,B) for(int I = (A); I < (B); ++I)
#define REP(I,N)   FOR(I,0,N)
#define ALL(A)     (A).begin(), (A).end()

using namespace std;

// }}}

class AvoidRoads
{
public:
	long long numWays(int width, int height, vector <string> bad)
	{
        vector<vector<long long> > grid(width + 1, vector<long long>(height + 1, 0));
        grid[0][0] = 1;

        for (int i = 1; i<= width; ++i)
            if (!isBad(bad, i - 1, 0, i, 0))
                grid[i][0] = grid[i - 1][0];

        for (int j = 1; j<= height; ++j)
            if (!isBad(bad, 0, j -1 , 0, j)) 
                grid[0][j] = grid[0][j - 1];

        for (int i = 1; i <= width; ++i) {
            for (int j = 1; j <= height; ++j) {
                if (!isBad(bad, i - 1, j, i, j))
                    grid[i][j] += grid[i - 1][j];
                if (!isBad(bad, i, j - 1, i, j))
                    grid[i][j] += grid[i][j - 1];
            }
        }
		return grid.back().back();
	}
private:
    string path(int a, int b, int c, int d)
    {
        stringstream ss;
        ss << a << " " << b << " " << c << " " << d;
        return ss.str();
    }

    bool isBad(vector<string> &bad, int a, int b, int c, int d)
    {
        return find(bad.begin(), bad.end(), path(a, b, c, d)) != bad.end();
    }
};

