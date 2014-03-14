#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int> > &matrix)
{
    int n = matrix.size();
    if (n <= 1)
        return;
    
    for (int i = 0, j = n - 1; i < j; ++i, --j) {
        for (int k = i; k < j; ++k) {
            int l = n - k - 1;
            int tmp = matrix[i][k];
            matrix[i][k] = matrix[l][i];
            matrix[l][i] = matrix[j][l];
            matrix[j][l] = matrix[k][j];
            matrix[k][j] = tmp;
        }
    }
}

int main(int argc, char *argv[])
{
    int a[4][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {1, 2, 3, 4},
        {5, 6, 7, 8}
    };

    vector<vector<int> > v(4, vector<int>(4));
    for (int i = 0; i < 4; ++i)
        for (int j = 0; j < 4; ++j)
            v[i][j] = a[i][j];

    rotate(v);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j)
            cout << v[i][j] << " ";
        cout << endl;
    }
    
    return 0;
}
