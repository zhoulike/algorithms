class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
        vector<vector<int> > ans(n, vector<int>(n));

        int num = 1;
        for (int layer = 0; layer <= n / 2; ++layer) {
            int j;
            for (j = layer; j < n - layer; ++j)
                ans[layer][j] = num++;
            for (j = layer + 1; j < n - layer; ++j)
                ans[j][n - layer - 1] = num++;
            for (j = n - layer - 2; j >= layer; --j)
                ans[n - layer - 1][j] = num++;
            for (j = n - layer - 2; j > layer; --j)
                ans[j][layer] = num++;
        }
        return ans;
    }
};
