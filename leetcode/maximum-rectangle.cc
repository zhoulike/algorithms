//turns 2D problem to 1D problem that has been solved
//similar method: turns 4sum to 3sum, then 2sum
class Solution {
public:
    int maximalRectangle(vector<vector<char> > &matrix) {
        if (matrix.empty() || matrix[0].empty())
            return 0;

        vector<int> height(matrix[0].size() + 1, 0); //one more dummy
        int max_area = 0;

        for (int i = 0; i < matrix.size(); ++i) {
            stack<int> stk;
            for (int j = 0; j < matrix[0].size(); ++j)  //calculate height
                if (matrix[i][j] == '1')
                    ++height[j];
                else
                    height[j] = 0;

            for (int j = 0; j < height.size();) {  //Largest Rectangle in Histogram
                if (stk.empty() || height[stk.top()] <= height[j])
                    stk.push(j++);
                else {
                    int pos = stk.top();
                    stk.pop();
                    max_area = max(max_area, height[pos] * (stk.empty()? j: j - stk.top() - 1));
                }
            }
        }
        return max_area;
    }
};
