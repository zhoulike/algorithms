class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        int n_row = matrix.size(), n_col = 0;
        if (n_row)
            n_col = matrix[0].size();
        int max_level = ceil(min(n_row, n_col) / 2.0);
        vector<int> ans;

        //top + right loop must cover a[0][0] to a[m - 1][n -1]. Otherwise, wrong answer if matrix = [[1]]
        for (int level = 0; level < max_level; ++level) {
            //top
            for (int k = level; k < n_col - level - 1; ++k)
                ans.push_back(matrix[level][k]);
            //right
            for (int k = level; k < n_row - level; ++k)
                ans.push_back(matrix[k][n_col - level - 1]);
            //bottom
            for (int k = n_col - level - 2; n_row - level - 1 > level && k > level; --k)
                ans.push_back(matrix[n_row - level - 1][k]);
            //left
            for (int k = n_row - level - 1; n_col - level - 1 > level && k > level; --k)
                ans.push_back(matrix[k][level]);
        }
        return ans;

    }
};