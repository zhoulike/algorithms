#include <iostream>
#include <vector>

using namespace std;

void zeroMatrix(vector<vector<int> > &v)
{
    if (v.size() == 0)
        return;

    bool row0 = false, column0 = false;
    for (auto i = 0; i < v.size(); ++i) {
        for (auto j = 0; j < v[i].size(); ++j) {
            if (v[i][j] == 0) {
                if (i == 0) //row 0 has 0
                    row0 = true;
                if (j == 0) //column 0 has 0
                    column0 = true;
                v[0][j] = v[i][0] = 0;
            }
        }
    }

    for (auto i = 1; i < v.size(); ++i) {
        for (auto j = 1; j < v[i].size(); ++j) {
            if (v[0][j] == 0 || v[i][0] == 0) {
                v[i][j] = 0;
            }
        }
    }

    if (column0)
        for (auto i = 1; i < v.size(); ++i)
            v[i][0] = 0;
    if (row0)
        for (auto j = 1; j < v[0].size(); ++j)
           v[0][j] = 0; 
}

int main(int argc, char *argv[])
{
    int a[3][3] = {
        {0, 2, 3},
        {4, 0, 6},
        {7, 8, 9}
    };

    vector<vector<int> > v(3, vector<int>(3));
    for (int i = 0; i < 3; ++i)
        for (int j = 0; j < 3; ++j)
            v[i][j] = a[i][j];

    zeroMatrix(v);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
