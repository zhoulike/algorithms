class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
    	if(obstacleGrid.size() <= 0 || obstacleGrid[0].size() <= 0 || obstacleGrid[0][0] == 1 || obstacleGrid.back().back() == 1)
    		return 0;

        vector<vector<int> > v(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), 0));
        v[0][0] = 1;

        for (int i = 0; i < obstacleGrid.size(); ++i) {
        	for (int j = 0; j < obstacleGrid[0].size(); ++j) {
        	    if(obstacleGrid[i][j] == 1)
        	        continue;
        
        		if (i - 1 >= 0 && obstacleGrid[i - 1][j] == 0)
        			v[i][j] += v[i - 1][j];
        		if (j - 1 >= 0 && obstacleGrid[i][j - 1] == 0)
        			v[i][j] += v[i][j - 1];
        	}
        }

        return v.back().back();        
    }
};