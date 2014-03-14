class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
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
};