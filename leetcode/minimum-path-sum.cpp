class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
        if(grid.size() <= 0)
            return 0;
            
        vector<vector<int> > sum(grid.size());
        for(int i = 0;i < sum.size(); ++i)
            sum[i].resize(grid[0].size(), 0);
        
        for(int i = 0;i < sum.size(); ++ i) {
            for(int j = 0;j < sum[0].size(); ++j){
                if(i >= 1 && j >= 1)
                    sum[i][j] = min(sum[i - 1][j], sum[i][j - 1]) + grid[i][j];
                else if(i >= 1)
                    sum[i][j] = sum[i - 1][j] + grid[i][j];
                else if(j >= 1)
                    sum[i][j] = sum[i][j - 1] + grid[i][j];
                else
                    sum[i][j] = grid[i][j];
            }
        }
        
        return sum[sum.size() - 1][sum[0].size() - 1];
    }
};