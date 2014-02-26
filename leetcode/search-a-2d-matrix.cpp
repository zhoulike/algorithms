class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
        int left, right, mid;
        for(left = 0, right = matrix.size() - 1; left <= right; ) {
            mid = left + ((right - left) >> 1);
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }

        if(right < 0 || left > matrix.size())
            return false;
        
        int pos = left - 1; //in this line, matrix[mid][0] < target, so pos = left - 1;
        for(left = 0, right = matrix[pos].size() - 1; left <= right;  ) {
            mid = left + ((right - left) >> 1);
            if(matrix[pos][mid] == target)
                return true;
            else if(matrix[pos][mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        
        return false;
    }
};